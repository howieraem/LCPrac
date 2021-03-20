/*
 * @lc app=leetcode.cn id=168 lang=java
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution {
    public String convertToTitle(int n) {
        StringBuilder ans = new StringBuilder();
        while (n > 0) {
            int c = n % 26;
            if (c == 0) {
                // case of 'Z'
                c = 26;
                n -= 1;
            }
            ans.insert(0, (char) ('A' + c - 1));
            n /= 26;
        }
        return ans.toString();
    }
}
// @lc code=end

