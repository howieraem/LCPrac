/*
 * @lc app=leetcode.cn id=49 lang=java
 *
 * [49] 字母异位词分组
 */
import java.util.*;

// @lc code=start
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> d = new HashMap<>();
        for (String s : strs) {
            // Let N be string length.

            // Below is faster for long strings, O(N)
            // int[] cnt = new int[26];
            // for (int i = 0; i < s.length(); ++i) {
            //     ++cnt[s.charAt(i) - 'a'];
            // }
            // StringBuilder key = new StringBuilder();
            // for (int i = 0; i < 26; ++i) {
            //     key.append((char) ('a' + i)).append(cnt[i]);
            // }
            // d.computeIfAbsent(key.toString(), k -> new ArrayList<>()).add(s);

            // Below is faster for short strings, O(N*log(N))
            char[] a = s.toCharArray();
            Arrays.sort(a);
            d.computeIfAbsent(String.valueOf(a), k -> new ArrayList<>()).add(s);
        }

        return new ArrayList<>(d.values());
    }
}
// @lc code=end
