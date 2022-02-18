#
# @lc app=leetcode id=329 lang=python3
#
# [329] Longest Increasing Path in a Matrix
#
from typing import *

# @lc code=start
class Solution:
    # T: O(m * n)
    # S: O(m * n)
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        dp = [[0] * n for _ in range(m)]
        D = (0, 1, 0, -1, 0)

        def memo_dfs(r, c):
            if dp[r][c] != 0:
                return dp[r][c]
            cur_max = 1

            for k in range(4):
                nr, nc = r + D[k], c + D[k + 1]
                if 0 <= nr < m and 0 <= nc < n and matrix[nr][nc] > matrix[r][c]:
                    cur_max = max(cur_max, memo_dfs(nr, nc) + 1)
            
            dp[r][c] = cur_max
            return dp[r][c]

        ans = 0
        for i in range(m):
            for j in range(n):
                ans = max(ans, memo_dfs(i, j))

        return ans

# @lc code=end

