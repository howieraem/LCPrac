#
# @lc app=leetcode.cn id=695 lang=python3
#
# [695] 岛屿的最大面积
#

# @lc code=start
class Solution:
    DIRNS = (-1, 0, 1, 0, -1)   # (-1, 0), (0, 1), (1, 0), (0, -1)

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0]) if m else 0
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    cur_area = 1
                    grid[i][j] = 0
                    stack = [(i, j)]
                    while len(stack):
                        (r, c) = stack.pop()
                        for k in range(4):
                            x = r + self.DIRNS[k]
                            y = c + self.DIRNS[k + 1]
                            if (x >= 0 and x < m and
                                y >= 0 and y < n and
                                grid[x][y]):
                                cur_area += 1
                                grid[x][y] = 0
                                stack.append((x, y))
                    ans = max(ans, cur_area)
        return ans
        
# @lc code=end
