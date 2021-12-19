/*
 * @lc app=leetcode.cn id=692 lang=java
 *
 * [692] 前K个高频单词
 */
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Map;
import java.util.HashMap;
import java.util.PriorityQueue;

// @lc code=start
class Solution {
    // T: O(n * log(k))
    // S: O(n)
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> cnts = new HashMap<>();
        for (String w : words) {
            cnts.put(w, cnts.getOrDefault(w, 0) + 1);
        }

        PriorityQueue<Map.Entry<String, Integer>> q = new PriorityQueue<>(
            k,
            (e1, e2) -> {
                // sort by count and then by natural order
                return e1.getValue() == e2.getValue() ? 
                    e2.getKey().compareTo(e1.getKey()) : e1.getValue() - e2.getValue();
            }
        );
        for (Map.Entry<String, Integer> e : cnts.entrySet()) {
            if (q.size() < k) {
                q.add(e);
            } else {
                Map.Entry<String, Integer> top = q.peek();
                int cnt = e.getValue(), topCnt = top.getValue();
                if (cnt > topCnt) {
                    q.poll();
                    q.add(e);
                } else if (cnt == topCnt) {
                    String w = e.getKey(), topW = top.getKey();
                    if (w.compareTo(topW) < 0) {
                        q.poll();
                        q.add(e);
                    }
                }
            }
        }

        List<String> res = new ArrayList<>();
        while (!q.isEmpty()) {
            res.add(q.poll().getKey());
        }
        Collections.reverse(res);
        return res;
    }
}
// @lc code=end

