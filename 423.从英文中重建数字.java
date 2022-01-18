/*
 * @lc app=leetcode.cn id=423 lang=java
 *
 * [423] 从英文中重建数字
 */

// @lc code=start
class Solution {
    public String originalDigits(String s) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }

        int[] res = new int[10];
        res[0] = cnt['z' - 'a'];    // 'z' only appears in "zero"
        res[2] = cnt['w' - 'a'];    // 'w' only appears in "two"
        res[4] = cnt['u' - 'a'];    // 'u' only appears in "four"
        res[6] = cnt['x' - 'a'];    // 'x' only appears in "six"
        res[8] = cnt['g' - 'a'];    // 'g' only appears in "eight"
        res[3] = cnt['h' - 'a'] - res[8];    // 'h' appears in "three" and "eight"
        res[5] = cnt['f' - 'a'] - res[4];
        res[7] = cnt['s' - 'a'] - res[6];
        res[9] = cnt['i' - 'a'] - res[5] - res[6] - res[8];
        res[1] = cnt['n' - 'a'] - res[7] - res[9] - res[9];

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < res[i]; ++j) {
                sb.append(i);
            }
        }
        return sb.toString();
    }
}
// @lc code=end

