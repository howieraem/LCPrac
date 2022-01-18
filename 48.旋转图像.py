#
# @lc app=leetcode.cn id=48 lang=python3
#
# [48] 旋转图像
#
from typing import List

# @lc code=start
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # Approach: rotate each inner "loop" of the matrix, 4 elements at a time.
        n = len(matrix)        
        for i in range(n // 2 + n % 2):
            for j in range(n // 2):
                tmp = matrix[n-1-j][i]
                matrix[n-1-j][i] = matrix[n-1-i][n-j-1]
                matrix[n-1-i][n-j-1] = matrix[j][n-1-i]
                matrix[j][n-1-i] = matrix[i][j]
                matrix[i][j] = tmp

    """
    Original solution, should not make a copy of the entire matrix:

    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        copy = [r[:] for r in matrix]
        for i in range(n):
            for j in range(n):
                matrix[i][j] = copy[n-j-1][i]
    """

# @lc code=end
