from typing import List

class Solution:
    # T: O(m ^ (n ^ 2)), n := 9, m := the number of grids with > 1 stones
    # S: O(n ^ 2) recursion stack
    def minimumMoves(self, grid: List[List[int]]) -> int:
        memo = {}  # without this, TLE in Python

        def get_memo_key(grid: List[List[int]]):
            k = [None] * 9
            ki = 0
            for i in range(3):
                for j in range(3):
                    k[ki] = grid[i][j]
                    ki += 1
            return tuple(k)

        def backtrack(grid: List[List[int]]) -> int:
            nonlocal memo
            k = get_memo_key(grid)
            v = memo.get(k, None)
            if v is not None:
                return v

            has_zero = False
            for i in range(3):
                for j in range(3):
                    if grid[i][j] == 0:
                        has_zero = True
                        break
                if has_zero:
                    break
            if not has_zero:
                # final state
                memo[k] = 0
                return 0

            ans = float('inf')
            for i in range(3):
                for j in range(3):
                    if grid[i][j] == 0:
                        for ni in range(3):
                            for nj in range(3):
                                if grid[ni][nj] > 1:
                                    dist = abs(i - ni) + abs(j - nj)
                                    grid[i][j] += 1
                                    grid[ni][nj] -= 1
                                    ans = min(ans, dist + backtrack(grid))
                                    grid[i][j] -= 1
                                    grid[ni][nj] += 1
            memo[k] = ans
            return ans

        return backtrack(grid)
