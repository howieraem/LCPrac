#
# @lc app=leetcode id=154 lang=python3
#
# [154] Find Minimum in Rotated Sorted Array II
#
from typing import *

# @lc code=start
class Solution:
    # Similar idea to Q153
    # T: O(n)
    # S: O(1)
    def findMin(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1
        while l < r:
            m = l + ((r - l) >> 1)
            if nums[m] > nums[r]:
                # the rotation pivot is on the right of mid
                l = m + 1
            elif nums[m] < nums[r]:
                # nums[m:r+1] is definitely sorted, so the pivot is on mid's left. 
                # Finding the smallest element is like finding the leftmost bound of some target. 
                # It is possible for the mid index to point to a smaller value than at least one  
                # other index in the list (at right), so we cannot discard the current m. 
                # Set r = m rather than m - 1.
                r = m
            else:
                # IMPORTANT:
                # Because of duplicates, we cannot tell the pivot is on mid's left or right,
                # We have to shift r linearly.
                r -= 1
        return nums[l]
        
# @lc code=end

