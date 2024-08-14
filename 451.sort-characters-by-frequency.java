import java.util.ArrayList;
import java.util.List;
import java.util.Map;

/*
 * @lc app=leetcode id=451 lang=java
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
class Solution {
    // Bucket sort
    // T: O(len(s))
    // S: O(len(s))
    public String frequencySort(String s) {
        Map<Character, Integer> freqs = new HashMap<>();
        for (char c : s.toCharArray()) {
            freqs.put(c, freqs.getOrDefault(c, 0) + 1);
        }

        List<Character>[] buckets = new List[s.length() + 1];
        for (Map.Entry<Character, Integer> kv : freqs.entrySet()) {
            Integer freq = kv.getValue();
            if (buckets[freq] == null) {
                buckets[freq] = new ArrayList<>();
            }
            buckets[freq].add(kv.getKey());
        }

        StringBuilder res = new StringBuilder();
        for (int freq = buckets.length - 1; freq > 0; freq--) {
            if (buckets[freq] != null) {
                for (Character c : buckets[freq]) {
                    for (int i = 0; i < freq; ++i) {
                        res.append(c);
                    }
                }
            }
        }
        return res.toString();
    }
}
// @lc code=end

