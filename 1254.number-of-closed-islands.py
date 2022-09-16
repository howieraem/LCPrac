#
# @lc app=leetcode id=1254 lang=python3
#
# [1254] Number of Closed Islands
#
from typing import *

# @lc code=start
class Solution:
    # T: O(m * n)
    # S: O(m * n) worst case recursion
    def closedIsland(self, grid: List[List[int]]) -> int:
        D = (1, 0, -1, 0, 1)
        m = len(grid)
        n = len(grid[0])

        def flood_fill(r: int, c: int):
            if 0 <= r < m and 0 <= c < n and grid[r][c] == 0:
                grid[r][c] = 1
                for d in range(4):
                    flood_fill(r + D[d], c + D[d + 1])
        
        # Change all 0's connected to the boundaries to 1's instead
        for r in range(m):
            for c in range(n):
                if r == 0 or c == 0 or r == m - 1 or c == n - 1:
                    flood_fill(r, c)

        # Find 0's that belong to closed islands
        ans = 0
        for r in range(m):
            for c in range(n):
                if grid[r][c] == 0:
                    ans += 1
                    flood_fill(r, c)
        return ans

# @lc code=end

