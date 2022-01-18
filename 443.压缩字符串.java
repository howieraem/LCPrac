/*
 * @lc app=leetcode.cn id=443 lang=java
 *
 * [443] 压缩字符串
 */

// @lc code=start
class Solution {
    public int compress(char[] chars) {
        int charStart = 0, numIdx = 0, n = chars.length;
        for (int i = 0; i < n; ++i) {
            if (i == n - 1 || chars[i + 1] != chars[i]) {
                chars[numIdx] = chars[charStart];
                numIdx++;
                if (i > charStart) {    // more than 1 characters
                    char[] digits = Integer.toString(i - charStart + 1).toCharArray();
                    for (char digit : digits) {
                        chars[numIdx++] = digit;
                    }
                }
                charStart = i + 1;
            }
        }
        return numIdx;
    }
}
// @lc code=end

