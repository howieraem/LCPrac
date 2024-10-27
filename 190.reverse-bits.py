#
# @lc app=leetcode id=190 lang=python3
#
# [190] Reverse Bits
#

# @lc code=start
class Solution:
    # T: O(s), s := no. of bits
    # S: O(s), s := no. of bits
    def reverseBits(self, n: int) -> int:
        ans = 0
        for _ in range(32):
            ans <<= 1  # shift left 1
            ans |= (n & 1)  # append rightmost bit to ans
            n >>= 1  # remove rightmost bit
        return ans
        
# @lc code=end

