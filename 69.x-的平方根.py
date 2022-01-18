#
# @lc app=leetcode.cn id=69 lang=python3
#
# [69] x 的平方根
#

# @lc code=start
class Solution:
    '''
    # Binary search method
    def mySqrt(self, x: int) -> int:
        l = 1
        r = x
        while l <= r:
            m = l + (r - l) // 2
            sqrt = x // m
            if sqrt == m:
                return m
            elif sqrt < m:
                r = m - 1
            else:
                l = m + 1
        return r
    '''

    # Newton method
    def mySqrt(self, x: int) -> int:
        a = x
        while a * a > x:
            a = (a + x // a) // 2
        return a
    

# @lc code=end

