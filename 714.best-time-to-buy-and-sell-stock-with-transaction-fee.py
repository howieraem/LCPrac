#
# @lc app=leetcode id=714 lang=python3
#
# [714] Best Time to Buy and Sell Stock with Transaction Fee
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def maxProfit(self, prices: List[int], fee: int) -> int:
        dp_sell = 0
        dp_buy = float('-inf')

        # transaction fee only apply to each buy-sell pair,
        # so assume it occurs at selling
        for p in prices:
            pre_dp_sell = dp_sell
            dp_sell = max(dp_sell, dp_buy + p - fee)
            dp_buy = max(dp_buy, pre_dp_sell - p)

        return dp_sell

# @lc code=end

