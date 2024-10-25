#
# @lc app=leetcode id=930 lang=python3
#
# [930] Binary Subarrays With Sum
#
from collections import defaultdict
from typing import *

# @lc code=start
class Solution:
    '''
    # 1-pass solution: prefix sum + two sum
    # T: O(n)
    # S: O(n)
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        prefix_sum_freqs = defaultdict(int)
        ans = 0
        prefix_sum = 0
        for x in nums:
            prefix_sum += x
            ans += prefix_sum_freqs[prefix_sum - goal]  # subarr sum equals prefix sum difference
            prefix_sum_freqs[prefix_sum] += 1
        return ans
    '''

    # Space-optimized 2-pass solution: sliding window helper
    # T: O(n)
    # S: O(1)
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        # It is hard to get the number of windows with an exact sum = goal.
        # Instead, we find the number of windows with sum less than or 
        # equal to goal and (goal - 1) respectively, and get the final answer 
        # from their difference.
        return self.numSubarrWithSumAtMostK(nums, goal) - \
                self.numSubarrWithSumAtMostK(nums, goal - 1)

    def numSubarrWithSumAtMostK(self, nums: List[int], k: int) -> int:
        window_sum = 0
        ans = 0
        l = 0
        for r in range(len(nums)):
            window_sum += nums[r]

            while l <= r and window_sum > k:
                window_sum -= nums[l]
                l += 1

            ans += r - l + 1   # num of subarrs added equals the feasible window length
        
        return ans

# @lc code=end

