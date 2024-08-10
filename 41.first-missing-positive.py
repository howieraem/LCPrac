#
# @lc app=leetcode id=41 lang=python3
#
# [41] First Missing Positive
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def firstMissingPositive(self, nums: List[int]) -> int:
        def swap(arr, i, j):
            # Explicitly define swap so that indices below won't be messed up
            arr[i], arr[j] = arr[j], arr[i]
        
        # Try reorganizing nums such that nums[i] = i + 1.
        # It will then be straightforward to find the missing smallest positive number.
        N = len(nums)

        # There will be at most N swaps because correctly arranged numbers will not be swapped any more.
        for i in range(N):
            while 0 < nums[i] <= N and nums[i] != nums[nums[i] - 1]:
                swap(nums, i, nums[i] - 1)

        # Works for min(nums) >= N
        for i in range(N):
            if nums[i] != i + 1:
                return i + 1
        
        return N + 1

# @lc code=end

