#
# @lc app=leetcode.cn id=200 lang=python3
#
# [200] 岛屿数量
#
from collections import deque

# @lc code=start
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        # Better space complexity O(min(nr, nc)) than DFS's O(nr*nc)
        nr = len(grid)
        if not nr:
            return 0
        nc = len(grid[0])

        ans = 0
        for r in range(nr):
            for c in range(nc):
                if grid[r][c] == '1':
                    ans += 1
                    grid[r][c] = '0'    # visited
                    neighbors = deque()
                    neighbors.append((r, c))
                    while neighbors:
                        row, col = neighbors.popleft()
                        if row >= 1 and grid[row - 1][col] == '1':
                            neighbors.append((row - 1, col))
                            grid[row - 1][col] = '0'
                        if row < nr - 1 and grid[row + 1][col] == '1':
                            neighbors.append((row + 1, col))
                            grid[row + 1][col] = '0'
                        if col >= 1 and grid[row][col - 1] == '1':
                            neighbors.append((row, col - 1))
                            grid[row][col - 1] = '0'
                        if col < nc - 1 and grid[row][col + 1] == '1':
                            neighbors.append((row, col + 1))
                            grid[row][col + 1] = '0'
        return ans

# @lc code=end

