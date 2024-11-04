#
# @lc app=leetcode id=69 lang=python3
#
# [69] Sqrt(x)
#

# @lc code=start
from math import ceil


class Solution:
    # Binary search + math
    # T: O(log(n))
    # S: O(1)
    def mySqrt(self, x: int) -> int:
        l, r = 1, ceil(x / 2.)

        while l <= r:
            m = (l + r) >> 1
            sqrt = x // m
            if sqrt == m:  # m * m == x
                return m
            elif sqrt < m: # m * m > x 
                r = m - 1
            else:          # m * m < x
                l = m + 1
        
        return r  # round down

# @lc code=end

