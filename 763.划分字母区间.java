/*
 * @lc app=leetcode.cn id=763 lang=java
 *
 * [763] 划分字母区间
 */
import java.util.*;

// @lc code=start
class Solution {
    public List<Integer> partitionLabels(String s) {
        int[] lastIdxs = new int[26];
        int n = s.length();
        char[] a = s.toCharArray();
        for (int i = 0; i < n; ++i) {
            lastIdxs[a[i] - 'a'] = i;
        }

        List<Integer> res = new ArrayList<>();
        int start = 0, end = 0;
        for (int i = 0; i < n; ++i) {
            end = Math.max(end, lastIdxs[a[i] - 'a']);

            // Partition as many as possble, so just partition
            // at the last occurrence of a type of character 
            // where some other types of characters don't appear
            // after this character
            if (i == end) {
                res.add(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
}
// @lc code=end

