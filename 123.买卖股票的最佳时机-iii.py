#
# @lc app=leetcode.cn id=123 lang=python3
#
# [123] 买卖股票的最佳时机 III
#
# from typing import List

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        K = 2   # maximum buy-sell attempts
        n = len(prices)
        dp = [[[0, 0] for _ in range (K+1)] for _ in range(n)]
        
        # Base cases 
        for i in range(n):
            # dp[i][0][0] = 0
            dp[i][0][1] = -float('inf')
        for j in range(1, K+1):
            # dp[0][j][0] = 0
            dp[0][j][1] = -prices[0]

        for i in range(1, n):
            for j in range(1, K+1):
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i])
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i])
        return dp[-1][-1][0]

# @lc code=end
# print(Solution().maxProfit([1,2,3,4,5]))
