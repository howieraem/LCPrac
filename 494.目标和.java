/*
 * @lc app=leetcode.cn id=494 lang=java
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
    /**
     * 把所有符号为正的数总和设为一个背包的容量，容量为x；把所有符号为负的数总和设为一个背包的容量，容量为y。
     * 在给定的数组中，有多少种选择方法让背包装满。令sum为数组的总和，则 x + y = sum。依题意两个背包的差等于S，
     * x - y = S。从而求得 x = (S + sum) / 2。基于上述分析，题目转换为背包问题：
     * 给定一个数组和一个容量为x的背包，求有多少种方式让背包装满。
     */
    public int findTargetSumWays(int[] nums, int S) {
        int sum = 0;
        for (int num : nums)  sum += num;
        if (Math.abs(S) > sum || (sum + S) % 2 == 1)  return 0;
        int len = (sum + S) / 2;
        int[] dp = new int[len + 1];
        dp[0] = 1;  // base case

        // 0-1背包，数组中的元素不可重复使用
        for (int num : nums) {
            for (int i = len; i >= num; --i) {
                dp[i] += dp[i - num];
            }
        }
        return dp[len];
    }
}
// @lc code=end

