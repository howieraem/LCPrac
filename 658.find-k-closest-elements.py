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
    # S: O(1) excl. output subarr copy
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        l = 0
        r = len(arr) - 1 - k
        while l <= r:
            m = l + ((r - l) >> 1)
            # subarr: arr[m] <= x <= arr[m + k]
            if x - arr[m] > arr[m + k] - x:  # arr already sorted
                l = m + 1
            else:
                r = m - 1
        
        return arr[l:l + k]  # this handles the case l + k >= len(arr)

# @lc code=end

