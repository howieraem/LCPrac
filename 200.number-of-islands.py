#
# @lc app=leetcode id=200 lang=python3
#
# [200] Number of Islands
#
from collections import deque
from typing import List

# @lc code=start
class Solution:
    # T: O(m * n), each cell visited only once
    # S: O(m * n)
    def numIslands(self, grid: List[List[str]]) -> int:
        D = (1, 0, -1, 0, 1)
        m = len(grid)
        n = len(grid[0])

        ans = 0
        q = deque()
        vis = set()  # just in case `grid` cannot be modified

        for i in range(m):
            for j in range(n):
                pos = (i, j)
                if pos not in vis and grid[i][j] == '1':
                    ans += 1
                    q.append(pos)
                    vis.add(pos)
                    while len(q):
                        r, c = q.popleft()
                        for d in range(4):
                            npos = (r + D[d], c + D[d + 1])
                            if 0 <= npos[0] < m and 0 <= npos[1] < n and grid[npos[0]][npos[1]] == '1' and npos not in vis:
                                q.append(npos)
                                vis.add(npos)
        
        return ans
                            


# @lc code=end

