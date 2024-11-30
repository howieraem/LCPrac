#
# @lc app=leetcode id=795 lang=python3
#
# [795] Number of Subarrays with Bounded Maximum
#
from typing import *

# @lc code=start
class Solution:
    # 1D DP + two pointers
    # T: O(n)
    # S: O(1) state compression
    def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
        ans = 0

        # dp[i] means the number of eligible subarrays ending with nums[i]
        dp = 0

        pre = -1  # handle initial edge case
        for i in range(len(nums)):
            if nums[i] < left:
                # we can only append nums[i] to all subarrays ending at nums[i - 1]
                # dp[i] = dp[i - 1]
                ans += dp
            elif nums[i] > right:
                # dp[i] = 0
                dp = 0
                pre = i
            else:  # left <= nums[i] <= right
                # valid subarrays: nums[pre + 1 ... i], nums[pre + 2 ... i], ..., nums[i]
                # dp[i] = i - pre
                dp = i - pre
                ans += dp
        
        return ans

# @lc code=end

