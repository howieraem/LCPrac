#
# @lc app=leetcode.cn id=122 lang=python3
#
# [122] 买卖股票的最佳时机 II
#
from typing import *

# @lc code=start
class Solution:
    '''
    # Math integral approach, or greedy approach: only aggregates positive price differences
    def maxProfit(self, prices: List[int]) -> int:
        ans = 0
        for i in range(1, len(prices)):
            pre, cur = prices[i-1:i+1]
            ans += (cur > pre) * (cur - pre)  # add diff if diff > 0 else 0
        return ans
    '''

    # DP approach (more general)
    # T: O(n)
    # S: O(1)
    def maxProfit(self, prices: List[int]) -> int:
        dp_i_0, dp_i_1 = 0, float('-inf')       # dp means profit at which day
        for price in prices:
            dp_i_0_pre = dp_i_0
            dp_i_0 = max(dp_i_0, dp_i_1 + price)        # sell
            dp_i_1 = max(dp_i_1, dp_i_0_pre - price)    # buy
        return dp_i_0

# @lc code=end

