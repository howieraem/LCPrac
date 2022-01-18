#
# @lc app=leetcode.cn id=188 lang=python3
#
# [188] 买卖股票的最佳时机 IV
#

# @lc code=start
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        """Making use of code in questions [122] and [123]."""
        n = len(prices)
        if k >= n // 2:
            '''Same as question [122].'''
            profit = 0
            for i in range(1, n):
                pre, cur = prices[i-1:i+1]
                profit += (cur > pre) * (cur - pre)
            return profit
        
        '''Below is a generalization of question [123].'''
        dp = [[[0, 0] for _ in range (k+1)] for _ in range(n)]
        
        # Base cases 
        for i in range(n):
            # dp[i][0][0] = 0
            dp[i][0][1] = -float('inf')
        for j in range(1, k+1):
            # dp[0][j][0] = 0
            dp[0][j][1] = -prices[0]

        for i in range(1, n):
            for j in range(1, k+1):
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i])
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i])
        return dp[-1][k][0]
    
# @lc code=end

