#
# @lc app=leetcode id=48 lang=python3
#
# [48] Rotate Image
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n ^ 2)
    # S: O(1)
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)

        # Math:
        # Given 2D rotation matrix R: [x', y'].T = R [x, y].T
        # R = [[cos(a), -sin(a)], 
        #      [sin(a), cos(a)]]
        # 90 deg clockwise: a = -pi/2 rad, R = [[0, 1], [-1, 0]], x' = -y, y' = x
        # 180 deg: a = pi rad, R = [[-1, 0], [0, -1]], x' = -x, y' = -y
        # 90 deg anticlockwise: a = pi/2 rad, R = [[0, -1], [1, 0]], x' = y, y' = -x

        # Swap/shift 4 corners each time
        for i in range(n >> 1):
            for j in range(n - (n >> 1)):
                # 90 deg clockwise
                # tmp = matrix[i][j]
                # matrix[i][j] = matrix[n - 1 - j][i]
                # matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j]
                # matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i]
                # matrix[j][n - 1 - i] = tmp
                matrix[i][j], matrix[n - 1 - j][i], matrix[n - 1 - i][n - 1 - j], matrix[j][n - 1 - i] = \
                    matrix[n - 1 - j][i], matrix[n - 1 - i][n - 1 - j], matrix[j][n - 1 - i], matrix[i][j]

                # 180 deg
                # matrix[i][j], matrix[n - 1 - j][i], matrix[n - 1 - i][n - 1 - j], matrix[j][n - 1 - i] = \
                #     matrix[n - 1 - i][n - 1 - j], matrix[j][n - 1 - i], matrix[i][j], matrix[n - 1 - j][i]

                # 90 deg counterclockwise
                # matrix[i][j], matrix[n - 1 - j][i], matrix[n - 1 - i][n - 1 - j], matrix[j][n - 1 - i] = \
                #     matrix[j][n - 1 - i], matrix[i][j], matrix[n - 1 - j][i], matrix[n - 1 - i][n - 1 - j]



# @lc code=end

