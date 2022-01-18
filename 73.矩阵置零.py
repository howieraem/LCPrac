#
# @lc app=leetcode.cn id=73 lang=python3
#
# [73] 矩阵置零
#
from typing import List

# @lc code=start
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        zero_pos = set()
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if not matrix[i][j]:
                    zero_pos.add((i, j))
        
        for i, j in zero_pos:
            matrix[i] = [0]*len(matrix[0])
            for row in matrix:
                row[j] = 0

    # A simplified approach with O(1) space
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        flag_col1 = False
        row = len(matrix)
        col = len(matrix[0])
        for i in range(row):
            if not matrix[i][0]: 
                flag_col1 = True
            for j in range(1, col):
                if not matrix[i][j]:
                    matrix[i][0] = matrix[0][j] = 0
        
        for i in range(row-1, -1, -1):
            for j in range(col-1, 0, -1):
                if not matrix[i][0] or not matrix[0][j]:
                    matrix[i][j] = 0
            if flag_col1: 
                matrix[i][0] = 0


# @lc code=end
# m=[[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]
# s = Solution()
# s.setZeroes(m)
# print(m)
