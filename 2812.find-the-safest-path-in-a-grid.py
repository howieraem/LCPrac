import heapq
from collections import deque

D = (0, 1, 0, -1, 0)

class Solution:
    # Compute the safety score matrix given the thieves
    # Similar to Q542
    def bfs(self, grid, score, n):
        q = deque()

        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    score[i][j] = 0  # at thief's location, safest dist is 0
                    q.append((i, j))

        while len(q) > 0:
            i, j = q.popleft()
            s = score[i][j]

            for d in range(4):
                ni = i + D[d]
                nj = j + D[d + 1]

                # Add 1 for manhattan distance
                if 0 <= ni < n and 0 <= nj < n and score[ni][nj] > s + 1:
                    score[ni][nj] = s + 1
                    q.append((ni, nj))

    # BFS + Dijkstra
    # T: O(n ^ 2 * log(n))
    # S: O(n ^ 2)
    def maximumSafenessFactor(self, grid):
        n = len(grid)
        if grid[0][0] == 1 or grid[n - 1][n - 1] == 1:
            return 0

        # Compute the safety score matrix given the thieves
        # score[i][j] means the manhattan dist to the nearest thief
        score = [[float('inf')] * n for _ in range(n)]  # init to infinity
        self.bfs(grid, score, n)

        vis = [[False] * n for _ in range(n)]
        vis[0][0] = True
        max_heap = [(-score[0][0], 0, 0)]  # maximize distance to any thieves
        heapq.heapify(max_heap)

        while len(max_heap) > 0:
            safe, i, j = heapq.heappop(max_heap)
            safe *= -1

            if i == n - 1 and j == n - 1:
                return safe

            for d in range(4):
                ni = i + D[d]
                nj = j + D[d + 1]

                if 0 <= ni < n and 0 <= nj < n and not vis[ni][nj]:
                    heapq.heappush(max_heap, (-min(safe, score[ni][nj]), ni, nj))
                    vis[ni][nj] = True

        return -1
