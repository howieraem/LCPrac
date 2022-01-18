#
# @lc app=leetcode.cn id=64 lang=python3
#
# [64] 最小路径和
#
from typing import List

# @lc code=start
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        # note: this function will modify grid.
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if i or j:
                    if not i:
                        grid[i][j] += grid[i][j-1]
                    elif not j:
                        grid[i][j] += grid[i-1][j]
                    else:
                        grid[i][j] = min(grid[i][j]+grid[i-1][j], grid[i][j]+grid[i][j-1])
        return grid[-1][-1]

# @lc code=end
# s = Solution()
# print(s.minPathSum([[1, 1]]))
