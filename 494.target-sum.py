#
# @lc app=leetcode id=494 lang=python3
#
# [494] Target Sum
#
from typing import *

# @lc code=start
class Solution:
    # T: O(n * target), n := len(nums)
    # S: O(n * target)
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        memo = dict()
        n = len(nums)

        def dp(i, cur):
            state = (i, cur)
            if state in memo:
                return memo[state]

            if i == n:
                return cur == target

            pos = dp(i + 1, cur + nums[i])
            neg = dp(i + 1, cur - nums[i])
            ret = pos + neg
            memo[state] = ret
            return ret

        return dp(0, 0)

# @lc code=end

