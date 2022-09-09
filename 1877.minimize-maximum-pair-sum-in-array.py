#
# @lc app=leetcode id=1877 lang=python3
#
# [1877] Minimize Maximum Pair Sum in Array
#
from typing import *

# @lc code=start
class Solution:
    # T: O(n * log(n))
    # S: O(n) for timsort
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        l = 0
        r = len(nums) - 1
        ans = 0
        while l < r:
            # To minimize the maximum pair sum, 
            # pair large values with small values.
            ans = max(ans, nums[l] + nums[r])
            l += 1
            r -= 1
        return ans

# @lc code=end

