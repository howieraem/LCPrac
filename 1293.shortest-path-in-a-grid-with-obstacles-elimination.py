#
# @lc app=leetcode id=1293 lang=python3
#
# [1293] Shortest Path in a Grid with Obstacles Elimination
#
import collections
from typing import *

# @lc code=start
class Solution:
    # T: O(m * n * k)
    # S: O(m * n * k)
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        M = len(grid)
        N = len(grid[0])
        vis = [[-1] * N for _ in range(M)] 
        q = collections.deque()
        q.append((0, 0, 0, k))
        while len(q):
            row, col, steps, obs_remove_quota = q.popleft()
            if row == M - 1 and col == N - 1:
                # Destination
                return steps
            if not (0 <= row < M and 0 <= col < N):
                # Out of bound
                continue

            if grid[row][col] == 1:
                if obs_remove_quota > 0:
                    obs_remove_quota -= 1
                else:
                    # Cannot remove more obstacles,
                    # so cell is not reachable
                    continue

            if vis[row][col] != -1 and vis[row][col] >= obs_remove_quota:
                # Cell has been visited with higher or equal quota, i.e. 
                # with fewer or equal obstacles removed, so skip the cell
                continue

            # Update quota
            vis[row][col] = obs_remove_quota
            steps += 1
            q.append((row + 1, col, steps, obs_remove_quota))
            q.append((row, col + 1, steps, obs_remove_quota))
            q.append((row - 1, col, steps, obs_remove_quota))
            q.append((row, col - 1, steps, obs_remove_quota))

        return -1  # no path


# @lc code=end

