#
# @lc app=leetcode id=1034 lang=python3
#
# [1034] Coloring A Border
#
from typing import *

# @lc code=start
D = (0, 1, 0, -1, 0)

class Solution:
    # DFS
    # T: O(m * n)
    # S: O(m * n)
    def colorBorder(self, grid: List[List[int]], row: int, col: int, color: int) -> List[List[int]]:
        m = len(grid)
        if m == 0:
            return grid
        n = len(grid[0])
        if n == 0:
            return grid
        
        component_color = grid[row][col]
        boundary_color = -component_color

        # This is needed because the inner cells of the component will have color restored.
        # Without this, DFS becomes backtracking.
        vis = [[False] * n for _ in range(m)]  

        def dfs(r, c):
            vis[r][c] = True
            grid[r][c] = boundary_color  # temp mark boundary

            for d in range(4):
                nr = r + D[d]
                nc = c + D[d + 1]
                if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == component_color and not vis[nr][nc]:
                    dfs(nr, nc)

            # Now check if the current cell is in the middle of a connected component,
            # i.e. all valid neighbors should have the same color
            is_inner = True
            for d in range(4):
                nr = r + D[d]
                nc = c + D[d + 1] 
                if not (0 <= nr < m and 0 <= nc < n and abs(grid[nr][nc]) == component_color):
                    is_inner = False
                    break
            
            if is_inner:
                # restore
                grid[r][c] = component_color
            # otherwise, the cell is on the boundary

        dfs(row, col)
        
        for r in range(m):
            for c in range(n):
                if grid[r][c] == boundary_color:
                    # boundary cell
                    grid[r][c] = color

        return grid

# @lc code=end

