#
# @lc app=leetcode.cn id=461 lang=python3
#
# [461] 汉明距离
#

# @lc code=start
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        xor = x ^ y
        dist = 0
        while xor:
            # mask out the rest bits
            # if xor & 1:
            dist += (xor & 1)

            # shift bits to the right (divided by 2) until 
            # all non-zero bits are counted
            xor >>= 1
        return dist

# @lc code=end
