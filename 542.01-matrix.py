#
# @lc app=leetcode id=542 lang=python3
#
# [542] 01 Matrix
#
from collections import deque
from typing import List

# @lc code=start
DIRN = (0, -1, 0, 1, 0)

class Solution:
    # BFS
    # T: O(m * n)
    # S: O(m * n)
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m = len(mat)
        if m == 0:
            return mat
        n = len(mat[0])

        q = deque()
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 0:
                    q.append((i, j))
                else:
                    mat[i][j] = -1  # marked as not processed

        while len(q) > 0:
            i, j = q.popleft()
            for d in range(4):
                ni = i + DIRN[d]
                nj = j + DIRN[d + 1]
                if 0 <= ni < m and 0 <= nj < n and mat[ni][nj] == -1:
                    q.append((ni, nj))
                    mat[ni][nj] = mat[i][j] + 1

        return mat

    '''
    # DP
    # T: O(m * n)
    # S: O(1)
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m = len(mat)
        if m == 0:
            return mat
        n = len(mat[0])
        INF = float('inf')

        # Two-pass: to avoid confusion/conflict, 
        # update top and left first, and then
        # reverse iterations to consider the other 
        # 2 directions.
        for i in range(m):
            for j in range(n):
                if mat[i][j] > 0:
                    top = mat[i - 1][j] if i > 0 else INF
                    left = mat[i][j - 1] if j > 0 else INF
                    mat[i][j] = min(top, left) + 1
        
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if mat[i][j] > 0:
                    bottom = mat[i + 1][j] if i < m - 1 else INF
                    right = mat[i][j + 1] if j < n - 1 else INF
                    mat[i][j] = min(mat[i][j], min(bottom, right) + 1)

        return mat
    '''

# @lc code=end

