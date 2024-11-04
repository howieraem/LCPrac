#
# @lc app=leetcode id=1368 lang=python3
#
# [1368] Minimum Cost to Make at Least One Valid Path in a Grid
#
from collections import deque
from typing import List

# @lc code=start
class Solution:
    # BFS + Memoized DFS
    # T: O(m * n)
    # S: O(m * n)
    def minCost(self, grid: List[List[int]]) -> int:
        D = ((0, 1), (0, -1), (1, 0), (-1, 0))
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])

        # Idea: greedily explore the grid. 
        # We will never detour the path to a node that we can already reach.
        
        memo = [[float('inf')] * n for _ in range(m)] 
        bfs_q = deque()

        # Check what cells can be reachable with the cur_cost
        # without actually changing the cell directions
        def dfs(r, c, cur_cost):
            if not (0 <= r < m and 0 <= c < n and memo[r][c] == float('inf')):
                return
            memo[r][c] = cur_cost
            bfs_q.append((r, c))   # assume we'll change direction with a cost next time
            next_dir = D[grid[r][c] - 1]
            nr = r + next_dir[0]
            nc = c + next_dir[1]
            dfs(nr, nc, cur_cost)

        cost = 0
        dfs(0, 0, cost)

        # BFS does level-order traversal
        while len(bfs_q) > 0:
            cost += 1   # max allowable cost
            qs = len(bfs_q)
            for _ in range(qs):
                r, c = bfs_q.popleft()
                for dr, dc in D:
                    nr = r + dr
                    nc = c + dc
                    dfs(nr, nc, cost)

        return memo[m - 1][n - 1]

# @lc code=end

