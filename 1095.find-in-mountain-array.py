#
# @lc app=leetcode id=1095 lang=python3
#
# [1095] Find in Mountain Array
#

class MountainArray:
   def get(self, index: int) -> int:
       raise NotImplementedError

   def length(self) -> int:
       raise NotImplementedError

# @lc code=start
# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:

class Solution:
    # Binary search 3 times
    # T: O(log(n))
    # S: O(1)
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        n = mountain_arr.length()

        # Binary search 1: find the peak: Q852
        l = 0
        r = n - 2  # n - 2 because nums[m+1] will be compared with nums[m]
        peak = -1
        while l <= r:
            m = l + ((r - l) >> 1)
            if mountain_arr.get(m) <= mountain_arr.get(m + 1):
                # nums[m] is in the ascending interval
                l = m + 1
            else:  # nums[m] > nums[m + 1]
                peak = m
                r = m - 1

        if peak == -1:
            return -1

        # Binary search 2: on the left ascending interval 
        # Left part first because we want the smaller index if multiple targets exist
        l = 0
        r = peak
        while l < r:
            m = l + ((r - l) >> 1)
            if mountain_arr.get(m) < target:
                l = m + 1
            else:
                r = m
        if mountain_arr.get(l) == target:
            return l

        # Binary search 3 (reversed): on the right descending interval
        l = peak
        r = n - 1
        while l < r:
            m = l + ((r - l) >> 1)
            if mountain_arr.get(m) > target:
                l = m + 1
            else:
                r = m
        if mountain_arr.get(l) != target:
            return -1
        return l

# @lc code=end

