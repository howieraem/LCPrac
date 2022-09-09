#
# @lc app=leetcode id=2174 lang=python3
#
# [2174] Remove All Ones With Row and Column Flips II
#
from typing import List

# @lc code=start
class Solution:
    # Worst case of recursion: operating on either just rows or on just cols (cannot be both)
    # T: O((m * n) ^ (max(m, n)))
    # S: O(max(m, n))
    def removeOnes(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        
        # Store values for backtracking
        tmp_row = [0] * n
        tmp_col = [0] * m
        
        ans = float('inf')
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    # Copy the original grid values, and 
                    # zero the whole row and the whole col
                    for r in range(m):
                        tmp_col[r] = grid[r][j]
                        grid[r][j] = 0    
                    for c in range(n):
                        tmp_row[c] = grid[i][c]
                        grid[i][c] = 0
                    
                    ans = min(ans, 1 + self.removeOnes(grid))
                    
                    # IMPORTANT: Restore row first and then col, 
                    # which is the opposite order of copying above
                    for c in range(n):
                        grid[i][c] = tmp_row[c]
                    for r in range(m):
                        grid[r][j] = tmp_col[r]

        return ans if ans < float('inf') else 0

# @lc code=end

