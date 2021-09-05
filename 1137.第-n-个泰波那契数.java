/*
 * @lc app=leetcode.cn id=1137 lang=java
 *
 * [1137] 第 N 个泰波那契数
 */

// @lc code=start
class Solution {
    public int tribonacci(int n) {
        if (n == 0)  return 0;
        int one = 0, two = 1, three = 1, cur = 1;
        for (int i = 3; i <= n; ++i) {
            cur = one + two + three;
            one = two;
            two = three;
            three = cur;
        }
        return cur;
    }
}
// @lc code=end

