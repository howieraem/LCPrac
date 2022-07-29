#
# @lc app=leetcode id=1730 lang=python3
#
# [1730] Shortest Path to Get Food
#
from collections import deque
from typing import List

# @lc code=start
class Solution:
    # T: O(m * n)
    # S: O(m * n)
    def getFood(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        dirs = (1, 0, -1, 0, 1)
        q = deque()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '*':
                    q.append((i, j))
                    break
        
        steps = 0
        while len(q):
            qs = len(q)
            for _ in range(qs):
                i, j = q.popleft()
                for d in range(4):
                    ni, nj = i + dirs[d], j + dirs[d + 1]
                    if 0 <= ni < m and 0 <= nj < n:
                        if grid[ni][nj] == '#':
                            return steps + 1
                        elif grid[ni][nj] == 'O':
                            grid[ni][nj] = 'V'
                            q.append((ni, nj))
            steps += 1
        return -1
        
# @lc code=end

