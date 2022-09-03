#
# @lc app=leetcode id=1102 lang=python3
#
# [1102] Path With Maximum Minimum Value
#
import heapq
from typing import List

# @lc code=start
class Solution:
    # Return the minimum value of the path of the maximum sum from top left to bottom right
    # T: O((m * n) * log(m * n))
    # S: O(m * n)
    def maximumMinimumPath(self, grid: List[List[int]]) -> int:
        D = (1, 0, -1, 0, 1)
        m, n = len(grid), len(grid[0])

        # negate value to simulate max heap
        pq = [(-grid[0][0], 0, 0)]

        vis = [[False] * n for _ in range(m)]
        vis[0][0] = True

        ans = grid[0][0]
        while len(pq):
            x, r, c = heapq.heappop(pq)
            ans = min(ans, -x)
            if r == m - 1 and c == n - 1:
                break
            
            for d in range(4):
                nr = r + D[d]
                nc = c + D[d + 1]
                if 0 <= nr < m and 0 <= nc < n and not vis[nr][nc]:
                    heapq.heappush(pq, (-grid[nr][nc], nr, nc))
                    vis[nr][nc] = True

        return ans


# @lc code=end

