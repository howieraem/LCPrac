#
# @lc app=leetcode id=2017 lang=python3
#
# [2017] Grid Game
#
from typing import List

# @lc code=start
class Solution:
    # Both robots can only move down once. Robot 1 has n possible paths.
    # As robot 1 moves first, robot 2 can only get some points from either top row or bottom row. 
    # Thus, we choose a path for robot 1 such that max(top_sum, bottom_sum) is minimized for robot 2. 
    # Note that maximizing robot 1's points doesn't guarantee the correct solution (game theory).
    # T: O(n)
    # S: O(1)
    def gridGame(self, grid: List[List[int]]) -> int:
        n = len(grid[0])
        top_sum = sum(grid[0])
        bottom_sum = 0
        
        ans = float('inf')

        for i in range(n):
            top_sum -= grid[0][i]
            ans = min(ans, max(top_sum, bottom_sum))
            bottom_sum += grid[1][i]

        return ans


# @lc code=end

