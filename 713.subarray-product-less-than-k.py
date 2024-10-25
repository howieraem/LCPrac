#
# @lc app=leetcode id=713 lang=python3
#
# [713] Subarray Product Less Than K
#
from typing import List

# @lc code=start
class Solution:
    # sliding window, only works for non-negative nums[i]
    # T: O(n)
    # S: O(n)
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k == 0:
            # if nums[i] can be zero, then we need to get the no. of zeros 
            # in nums, and do some calculations with the no. of positive 
            # numbers in nums
            return 0
        
        window_product = 1  # different from window sum
        ans = 0
        l = 0
        for r in range(len(nums)):
            window_product *= nums[r]

            while l <= r and window_product >= k:
                window_product //= nums[l]
                l += 1

            ans += r - l + 1  # no. of subarr added equals the length of the feasible window

        return ans


        
# @lc code=end

