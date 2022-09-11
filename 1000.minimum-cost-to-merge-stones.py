#
# @lc app=leetcode id=1000 lang=python3
#
# [1000] Minimum Cost to Merge Stones
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n ^ 3 * K)
    # S: O(n ^ 2 * K)
    def mergeStones(self, stones: List[int], K: int) -> int:
        n = len(stones)
        # Impossible to finish with 1 pile if merging exactly k consecutive piles every move
        if (n - 1) % (K - 1) != 0:
            return -1  
        
        # For O(1) computation of interval sum, i.e. sum(stones[i:j])
        pre_sum = [0] * (n + 1)
        for i in range(1, n + 1):
            pre_sum[i] = pre_sum[i - 1] + stones[i - 1]
        
        INF = float('inf')

        # dp[i][j][k] means the cost to merge stones[i+1:j+1] into k piles
        dp = [[[INF] * (K + 1) for _ in range(n + 1)] for _ in range(n + 1)]
        dp[0][0][0] = 0
        for i in range(1, n + 1):
            dp[i][i][1] = 0  # base case, one stone is a pile on its own
        
        for length in range(2, n + 1):
            for i in range(1, (n - length + 1) + 1):
                j = i + length - 1
                for k in range(2, K + 1):
                    for idx in range(i, j):
                        # Need to know the minimum cost of merging left part to k - 1 piles and 
                        # right part to 1 pile.
                        if dp[i][idx][k - 1] == INF or dp[idx + 1][j][1] == INF:
                            continue
                        dp[i][j][k] = min(dp[i][j][k], dp[i][idx][k - 1] + dp[idx + 1][j][1])
                if dp[i][j][K] == INF:
                    continue

                # Previously we have k piles between i and j, and now we have need to merge them into 1 pile i and j. 
                # How it goes from k piles to 1 piles directly? Just merge all the k piles together, where size of 
                # each pile is sum of all elements in that piles, so the cost of merge all k piles together is the 
                # sum of all elements in i and j.
                dp[i][j][1] = dp[i][j][K] + pre_sum[j] - pre_sum[i - 1]

        return dp[1][n][1]

# @lc code=end

