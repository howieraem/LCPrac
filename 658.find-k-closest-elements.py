#
# @lc app=leetcode id=658 lang=python3
#
# [658] Find K Closest Elements
#
from typing import *

# @lc code=start
class Solution:
    # Binary search, find a subarray with length k instead of a number
    # T: O(log(n - k) + k)
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        l = 0
        r = len(arr) - k
        while l < r:
            m = (l + r) >> 1
            if x - arr[m] > arr[m + k] - x:
                l = m + 1
            else:
                r = m
        return arr[l:l + k]

# @lc code=end

