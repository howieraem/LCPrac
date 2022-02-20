#
# @lc app=leetcode id=69 lang=python3
#
# [69] Sqrt(x)
#

# @lc code=start
from math import ceil


class Solution:
    def mySqrt(self, x: int) -> int:
        l, r = 1, ceil(x / 2.)

        while l <= r:
            m = (l + r) >> 1
            sqrt = x // m
            if sqrt == m:
                return m
            elif sqrt < m:
                r = m - 1
            else:
                l = m + 1
        return r

# @lc code=end

