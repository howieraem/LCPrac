import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=1657 lang=java
 *
 * [1657] 确定两个字符串是否接近
 */

// @lc code=start
class Solution {
    public boolean closeStrings(String word1, String word2) {
        // 长度不同，不能转换
        if (word1.length() != word2.length())  return false;

        boolean[] w1Keys = new boolean[26], w2Keys = new boolean[26];
        int[] w1Cnts = new int[26], w2Cnts = new int[26];
        for (char c : word1.toCharArray()) {
            int idx = (int) c - 'a';
            w1Keys[idx] = true;
            ++w1Cnts[idx];
        }
        for (char c : word2.toCharArray()) {
            int idx = (int) c - 'a';
            w2Keys[idx] = true;
            ++w2Cnts[idx];
        }

        // 包含的字符不一致，不能转换
        if (!Arrays.equals(w1Keys, w2Keys))  return false;
        
        Arrays.sort(w1Cnts);
        Arrays.sort(w2Cnts);

        // 字符集相同，但字符出现次数经排序后不一致，不能转换
        if (!Arrays.equals(w1Cnts, w2Cnts))  return false;
        return true;    // 可经多次操作转换
    }
}
// @lc code=end

