/*
 * @lc app=leetcode id=347 lang=java
 *
 * [347] Top K Frequent Elements
 */
import java.util.*;

// @lc code=start
class Solution {
    // T: O(n)
    // S: O(n)
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> freqs = new HashMap<>();
        int max_freq = 1;
        for (int x : nums) {
            int freq = freqs.getOrDefault(x, 0) + 1;
            freqs.put(x, freq);
            max_freq = Math.max(max_freq, freq);
        }
        
        // max_freq <= n
        List<Integer>[] buckets = new List[max_freq + 1];
        for (Map.Entry<Integer, Integer> e : freqs.entrySet()) {
            int freq = e.getValue();
            if (buckets[freq] == null) {
                buckets[freq] = new ArrayList<>();
            }
            buckets[freq].add(e.getKey());
        }

        int[] res = new int[k];
        int p = 0;
        for (int i = max_freq; i >= 0; --i) {
            List<Integer> sameFreqNums = buckets[i];
            if (sameFreqNums != null) {
                for (int x : sameFreqNums) {
                    res[p++] = x;
                    if (p == k) {
                        return res;
                    }
                }
            }
        }
        return res;
    }
}
// @lc code=end

