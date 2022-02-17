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
        dp = dict()
        n = len(nums)

        def memo_dfs(i, cur):
            state = (i, cur)
            if state in dp:
                return dp[state]

            if i == n:
                return cur == target

            pos = memo_dfs(i + 1, cur + nums[i])
            neg = memo_dfs(i + 1, cur - nums[i])
            ret = pos + neg
            dp[state] = ret
            return ret

        return memo_dfs(0, 0)

# @lc code=end

