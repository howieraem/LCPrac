#
# @lc app=leetcode id=317 lang=python3
#
# [317] Shortest Distance from All Buildings
#
from collections import deque
from typing import List

# @lc code=start
class Solution:
    # BFS for each building, compute the shortest dist from each 0 to that building (better if the number of 0s is much greater)
    # T: O((m * n) ^ 2)
    # S: O(m * n)
    def shortestDistance(self, grid: List[List[int]]) -> int:
        D = (1, 0, -1, 0, 1)
        m = len(grid)
        n = len(grid[0])
        
        dists = [[0] * n for _ in range(m)]
        reachable = [[0] * n for _ in range(m)]
        buildings = 0

        q = deque()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    buildings += 1
                    q.clear()
                    q.append((i, j))

                    vis = [[False] * n for _ in range(m)]
                    steps = 1

                    while len(q):
                        qs = len(q)
                        for _ in range(qs):
                            r, c = q.popleft()
                            for d in range(4):
                                nr = r + D[d]
                                nc = c + D[d + 1]
                                if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == 0 and not vis[nr][nc]:
                                    dists[nr][nc] += steps
                                    reachable[nr][nc] += 1
                                    vis[nr][nc] = True

                                    # Optimization: only add to queue when current 0 can be reached by all previous buildings
                                    if reachable[nr][nc] == buildings:
                                        q.append((nr, nc))
                        steps += 1

        INF = float('inf')
        ans = INF
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0 and reachable[i][j] == buildings:
                    ans = min(ans, dists[i][j])
        return ans if ans < INF else -1

# @lc code=end

