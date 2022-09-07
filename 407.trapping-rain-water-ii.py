#
# @lc app=leetcode id=407 lang=python3
#
# [407] Trapping Rain Water II
#
import heapq
from typing import List

# @lc code=start
class Solution:
    # T: O(m * n * log(m * n))
    # S: O(m * n)
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        D = (1, 0, -1, 0, 1)
        m = len(heightMap)
        n = len(heightMap[0])

        # Law of the minimum: The water trapped at a cell is determined by 
        # the minimum height of its 4 boundaries
        min_heap = []
        vis = [[False] * n for _ in range(m)]

        # Add the 4 boundaries. Cells on the boundaries cannot trap water.
        for i in range(m):
            heapq.heappush(min_heap, (heightMap[i][0], i, 0))
            vis[i][0] = True
            heapq.heappush(min_heap, (heightMap[i][n - 1], i, n - 1))
            vis[i][n - 1] = True
        for j in range(1, n - 1):  # IMPORTANT: don't add the corners again
            heapq.heappush(min_heap, (heightMap[0][j], 0, j))
            vis[0][j] = True
            heapq.heappush(min_heap, (heightMap[m - 1][j], m - 1, j))
            vis[m - 1][j] = True

        ans = 0
        while len(min_heap):
            # Start from the current minimum height. 
            # If there are lower cells when searching towards the center, 
            # then we know these can trap water.
            h, r, c = heapq.heappop(min_heap)
            for d in range(4):
                nr = r + D[d]
                nc = c + D[d + 1]
                if 0 <= nr < m and 0 <= nc < n and not vis[nr][nc]:
                    # Boundary replacement: The above "law of the minimum" applies only to neighbors of 
                    # the lowest part of current boundary. After that the lowest part will be replaced 
                    # by its neighbors. The height of the new parts of the boundary will be the larger 
                    # one of the old boundary height and the height from the elevation map.
                    if h > heightMap[nr][nc]:
                        ans += h - heightMap[nr][nc]
                        heapq.heappush(min_heap, (h, nr, nc))
                    else:
                        heapq.heappush(min_heap, (heightMap[nr][nc], nr, nc))
                    vis[nr][nc] = True
        return ans
        
# @lc code=end

