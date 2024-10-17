#
# @lc app=leetcode id=1471 lang=python3
#
# [1471] The k Strongest Values in an Array
#
from typing import List

# @lc code=start
class Solution:
    # Two pointers
    # T: O(n * log(n))
    # S: O(n)
    def getStrongest(self, arr: List[int], k: int) -> List[int]:
        arr = sorted(arr)
        l = 0
        r = len(arr) - 1

        median = arr[(len(arr) - 1) >> 1]  # use the problem's definition instead

        while k > 0:
            if arr[r] - median >= median - arr[l]:
                r -= 1
            else:
                l += 1 
            k -= 1

        return arr[:l] + arr[r + 1:]  # any permutation is okay

# @lc code=end

