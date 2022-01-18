#
# @lc app=leetcode.cn id=231 lang=python3
#
# [231] 2的幂
#

# @lc code=start
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        # If only keeping the rightmost bit 1 will not change
        # the value of n, then it is power of two.
        if not n:
            return False
        return n & (-n) == n
        
# @lc code=end
