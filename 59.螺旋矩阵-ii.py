#
# @lc app=leetcode.cn id=59 lang=python3
#
# [59] 螺旋矩阵 II
#
from typing import List

# @lc code=start
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        num = 1
        matrix = [[0]*n for _ in range(n)]
        left, right, top, bottom = 0, n - 1, 0, n - 1
        while left <= right and top <= bottom:
            for column in range(left, right + 1):
                matrix[top][column] = num
                num += 1
            for row in range(top + 1, bottom + 1):
                matrix[row][right] = num
                num += 1
            if left < right and top < bottom:
                for column in range(right - 1, left, -1):
                    matrix[bottom][column] = num
                    num += 1
                for row in range(bottom, top, -1):
                    matrix[row][left] = num
                    num += 1
            left, right, top, bottom = left + 1, right - 1, top + 1, bottom - 1
        return matrix

# @lc code=end
# s = Solution()
# print(s.generateMatrix(3))
