#
# @lc app=leetcode id=1444 lang=python3
#
# [1444] Number of Ways of Cutting a Pizza
#
from typing import List

# @lc code=start
class Solution:
    # Memoized DFS (top-bottom 3D DP) + prefix sum
    # T: O(n ^ 3)
    # S: O(n ^ 3)
    def ways(self, pizza: List[str], k: int) -> int:
        MOD = 1_000_000_007
        m = len(pizza)
        n = len(pizza[0])

        # memo[k][r][c] means how many ways to cut pizza[r:][c:] with k cuts
        memo = [[[-1] * n for _ in range(m)] for _ in range(k)]
        k -= 1

        # prefix_sums[r][c] means no. of apples in pizza[r:][c:]
        # iterate reversely because we are cutting the top or the left first
        prefix_sums = [[0] * (n + 1) for _ in range(m + 1)]
        for r in range(m - 1, -1, -1):
            for c in range(n - 1, -1, -1):
                prefix_sums[r][c] = prefix_sums[r][c + 1] + prefix_sums[r + 1][c] - prefix_sums[r + 1][c + 1] + (pizza[r][c] == 'A')

        def dfs(k, r, c):
            if prefix_sums[r][c] == 0:
                return 0
            if k == 0:
                # base case
                return 1
            
            if memo[k][r][c] != -1:
                return memo[k][r][c]
            
            ans = 0

            # cut horizontally
            for nr in range(r + 1, m):
                if prefix_sums[r][c] - prefix_sums[nr][c] > 0:
                    # cut if top piece contains at least one apple
                    ans = (ans + dfs(k - 1, nr, c)) % MOD
            
            # cut vertically
            for nc in range(c + 1, n):
                if prefix_sums[r][c] - prefix_sums[r][nc] > 0:
                    # cut if left piece contains at least one apple
                    ans = (ans + dfs(k - 1, r, nc)) % MOD
            
            memo[k][r][c] = ans
            return ans
        
        return dfs(k, 0, 0)

# @lc code=end

