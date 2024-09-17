#
# @lc app=leetcode id=1380 lang=python3
#
# [1380] Lucky Numbers in a Matrix
#
from typing import List

# @lc code=start
class Solution:
    # T: O(m * n)
    # S: O(1)
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix)
        if m == 0:
            return []
        n = len(matrix[0])

        row_mins = [float('inf')] * m
        col_maxs = [0] * n

        for i in range(m):
            for j in range(n):
                row_mins[i] = min(row_mins[i], matrix[i][j])
                col_maxs[j] = max(col_maxs[j], matrix[i][j])

        for i in range(m):
            for j in range(n):
                if matrix[i][j] == row_mins[i] == col_maxs[j]:
                    return [matrix[i][j]]
        
        return []

# @lc code=end

