/*
 * @lc app=leetcode.cn id=299 lang=java
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution {
    public String getHint(String secret, String guess) {
        int[] digitCnts = new int[10];
        int A = 0, B = 0;
        for (int i = 0; i < secret.length(); ++i) {
            char c1 = secret.charAt(i), c2 = guess.charAt(i);
            if (c1 == c2) {
                ++A;
            } else {
                if (digitCnts[c1 - '0'] < 0) {
                    // digit has appeared in guess
                    ++B;
                }
                if (digitCnts[c2 - '0'] > 0) {
                    // digit has appeared in secret
                    ++B;
                }
                digitCnts[c1 - '0']++;
                digitCnts[c2 - '0']--;
            }
        }
        StringBuilder ans = new StringBuilder();
        return ans.append(A).append('A').append(B).append('B').toString();
    }
}

// @lc code=end

