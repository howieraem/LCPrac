#
# @lc app=leetcode id=1428 lang=python3
#
# [1428] Leftmost Column with at Least a One
#
class BinaryMatrix(object):
   def get(self, row: int, col: int) -> int:
       pass

   def dimensions(self) -> list:
       pass

# @lc code=start
# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
#class BinaryMatrix(object):
#    def get(self, row: int, col: int) -> int:
#    def dimensions(self) -> list[]:

class Solution:
    # T: O(m + n)
    # S: O(1)
    def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
        m, n = binaryMatrix.dimensions()
        ans = -1

        # Row-sorted, start from the top right corner
        r, c = 0, n - 1

        while r < m and c >= 0:
            if binaryMatrix.get(r, c) == 1:
                ans = c
                c -= 1
            else:
                # This row up to column c is still 0,
                # and 1 must not appear before c,
                # so check the next row instead
                r += 1
        return ans

# @lc code=end

