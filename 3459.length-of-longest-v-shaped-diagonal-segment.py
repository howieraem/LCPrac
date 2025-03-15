from functools import lru_cache
from typing import List

class Solution:
    # Memoized DFS + 5D DP
    # T: O(m * n * d * v * t), d := no. of directions, v := value space size, t := no. of turns
    # S: O(m * n * d * v * t)
    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        DIRN = ((-1, 1), (1, 1), (1, -1), (-1, -1))
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])

        @lru_cache(None)
        def dfs(r, c, d, val, is_turned):
            r += DIRN[d][0]
            c += DIRN[d][1]
            if not (0 <= r < m and 0 <= c < n and grid[r][c] == val):
                return 1

            val = 0 if val == 2 else 2
            ans = 1 + dfs(r, c, d, val, is_turned)
            if not is_turned:
                ans = max(ans, 1 + dfs(r, c, (d + 1) % len(DIRN), val, True))
            return ans 

        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    ans = max(ans, 1)
                    for d in range(len(DIRN)):
                        ans = max(ans, dfs(i, j, d, 2, False))

        return ans
