#
# @lc app=leetcode id=1219 lang=python3
#
# [1219] Path with Maximum Gold
#
from typing import *

# @lc code=start
D = (1, 0, -1, 0, 1)

class Solution:
    # backtracking
    # T: O(3 ^ (m * n))
    # S: O(3 ^ (m * n))
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        if n == 0:
            return 0

        def backtrack(r, c):
            if not (0 <= r < m and 0 <= c < n) or grid[r][c] == 0:
                return 0
            
            val = grid[r][c]
            grid[r][c] = 0

            path_val = float('-inf')
            for d in range(4):
                nr = r + D[d]
                nc = c + D[d + 1]
                path_val = max(path_val, backtrack(nr, nc))
            
            grid[r][c] = val
            return path_val + val

        ans = float('-inf')
        for r in range(m):
            for c in range(n):
                ans = max(ans, backtrack(r, c))
        return ans



# @lc code=end

