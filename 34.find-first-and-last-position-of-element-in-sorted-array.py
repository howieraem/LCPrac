#
# @lc app=leetcode id=34 lang=python3
#
# [34] Find First and Last Position of Element in Sorted Array
#
from bisect import bisect_left, bisect_right
from typing import *

# @lc code=start
class Solution:
    # T: O(log(n))
    # S: O(1)
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)

        # Find left most
        l, r = 0, n - 1
        while l <= r:
            m = l + ((r - l) >> 1)
            if nums[m] >= target:
                r = m - 1
            else:
                l = m + 1
        if l >= n or nums[l] != target:
            return [-1, -1]
        ans_l = l

        # Find right most 
        # (note that setting l = 0 is not necessary if two searches are consecutive)
        l, r = 0, n - 1
        while l <= r:
            m = l + ((r - l) >> 1)
            if nums[m] <= target:
                l = m + 1
            else:
                r = m - 1
        if r < 0 or nums[r] != target:
            return [-1, -1]
        return [ans_l, r]

    """
    # Solution with built-in functions
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not len(nums):
            return [-1, -1]
        l = bisect_left(nums, target)
        r = bisect_right(nums, target)
        return [l, r - 1] if l < r else [-1, -1]
    """
        
# @lc code=end

