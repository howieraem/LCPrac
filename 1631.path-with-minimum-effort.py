#
# @lc app=leetcode id=1631 lang=python3
#
# [1631] Path With Minimum Effort
#
import heapq
from typing import List

# @lc code=start
class Solution:
    # Dijkstra's Algo
    # T: O(m * n * log(m * n))
    # S: O(m * n)
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        D = (0, 1, 0, -1, 0)
        m = len(heights)
        n = len(heights[0])
        dists = [[float('inf')] * n for _ in range(m)]
        dists[0][0] = 0

        # heap elem: (effort, row, col)
        min_heap = [(0, 0, 0)]
        while len(min_heap):
            d, r, c = heapq.heappop(min_heap)
            if d > dists[r][c]:
                # there has been at least a path with less effort
                continue
            if r == m - 1 and c == n - 1:
                return d  # reached target
            
            for i in range(4):
                nr = r + D[i]
                nc = c + D[i + 1]
                if 0 <= nr < m and 0 <= nc < n:
                    nd = max(d, abs(heights[nr][nc] - heights[r][c]))
                    if dists[nr][nc] > nd:
                        dists[nr][nc] = nd
                        heapq.heappush(min_heap, (nd, nr, nc))

        return 0  # not reachable, just to match function signature

# @lc code=end

