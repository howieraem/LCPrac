#
# @lc app=leetcode id=280 lang=python3
#
# [280] Wiggle Sort
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # if i is odd, then nums[i] >= nums[i - 1]
        # if i is even, then nums[i] <= nums[i - 1]
        # Thus, we only need to fix the anti-patterns in nums.
        # Correctness can be proven by induction.
        for i in range(1, len(nums)):
            if ((i & 1) == 0) == (nums[i] > nums[i - 1]):
                nums[i - 1], nums[i] = nums[i], nums[i - 1]

        
# @lc code=end

