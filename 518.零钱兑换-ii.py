#
# @lc app=leetcode.cn id=518 lang=python3
#
# [518] 零钱兑换 II
#

# @lc code=start
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n = len(coins)
        dp = [0] * (amount + 1)
        dp[0] = 1  # when amount = 0, there can be only 1 coin combination which is none

        for coin in coins:
            for j in range(1, amount + 1):
                if j >= coin:
                    dp[j] += dp[j - coin]
        
        return dp[amount]
        
# @lc code=end

