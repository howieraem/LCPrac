#
# @lc app=leetcode id=153 lang=python3
#
# [153] Find Minimum in Rotated Sorted Array
#
from typing import *

# @lc code=start
class Solution:
    # Binary-search the rotation pivot, so converge the left and right bounds on that point
    # T: O(log(n))
    # S: O(1)
    def findMin(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1
        while l < r:
            m = l + ((r - l) >> 1)
            if nums[m] > nums[r]:
                # the rotation pivot is on the right of m
                l = m + 1
            else:
                # We can tell nums[m:r+1] is sorted as there is no duplicate, so the pivot is on mid's left.  
                # Finding the smallest element is like finding the leftmost bound of some target. 
                # It is possible for the mid index to point to a smaller value than at least 
                # one other index in the list (at right), so we cannot discard the current m.
                # Set r = m rather than m - 1.
                r = m
        return nums[l]
        
# @lc code=end

