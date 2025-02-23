from typing import *

class Solution:
    # Hash map
    # T: O(n ^ 2), n := len(grid)
    # S: O(n ^ 2)
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n = len(grid) * len(grid)
        freqs = [0] * n

        for i in range(len(grid)):
            for j in range(len(grid[i])):
                freqs[grid[i][j] - 1] += 1

        missing = None
        repeated = None

        for x in range(1, n + 1):
            if freqs[x - 1] == 0:
                missing = x
            elif freqs[x - 1] == 2:
                repeated = x
            
            if missing is not None and repeated is not None:
                return [repeated, missing]
        
        return [None, None]
