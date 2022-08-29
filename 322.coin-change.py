#
# @lc app=leetcode id=322 lang=python3
#
# [322] Coin Change
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n * amount)
    # S: O(amount)
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1):
            for coin in coins:
                if coin <= i:
                    dp[i] = min(dp[i], dp[i - coin] + 1)
        return dp[amount] if dp[amount] <= amount else -1

# @lc code=end

