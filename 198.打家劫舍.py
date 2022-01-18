#
# @lc app=leetcode.cn id=198 lang=python3
#
# [198] 打家劫舍
#
from typing import List

# @lc code=start
class Solution:
    def rob(self, nums: List[int]) -> int:
        '''
        n = len(nums)
        if not n:
            return 0
        elif n == 1:
            return nums[0]
        '''
        
        # `dp = [0]*n` can be optimized to two rolling variables,
        # because current sum is only relevant to the previous
        # two sums
        i_2 = i_1 = 0  # `initially dp[0] and dp[1]`
        for i in range(len(nums)):
            # `dp[i] = max(dp[i-2] + nums[i], dp[i-1])`
            tmp = i_1
            i_1 = max(i_2 + nums[i], i_1)
            i_2 = tmp
        return i_1     # `dp[-1]`

# @lc code=end
