/*
 * @lc app=leetcode.cn id=171 lang=java
 *
 * [171] Excel表列序号
 */

// @lc code=start
class Solution {
    public int titleToNumber(String s) {
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            ans = ans*26 + s.charAt(i) - 'A' + 1;
        }
        return ans;
    }
}
// @lc code=end

