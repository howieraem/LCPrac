#
# @lc app=leetcode id=694 lang=python3
#
# [694] Number of Distinct Islands
#
from collections import deque
from typing import *

# @lc code=start
class Solution:
    def numDistinctIslands(self, grid: List[List[int]]) -> int:
        D = (1, 0, -1, 0, 1)
        m, n = len(grid), len(grid[0])
        island = ""
        islands = set()

        # DFS
        def dfs(r, c, dirn):
            if not (0 <= r < m and 0 <= c < n and grid[r][c]):
                return False

            grid[r][c] = 0
            nonlocal island
            island += str(dirn)

            for k in range(4):
                dfs(r + D[k], c + D[k + 1], k)

            island += ','

        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    island = ""
                    dfs(i, j, ',')
                    islands.add(island)

        '''
        # BFS
        q = deque()

        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    grid[i][j] = 0
                    q.append((i, j))

                    island = ","

                    while len(q):
                        r, c = q.popleft()
                        for k in range(4):
                            nr, nc = r + D[k], c + D[k + 1]
                            if 0 <= nr < m and 0 <= nc < n and grid[nr][nc]:
                                grid[nr][nc] = 0
                                q.append((nr, nc))
                                island += str(k)
                        island += ','
                    
                    islands.add(island)
        '''
        
        return len(islands)

# @lc code=end

