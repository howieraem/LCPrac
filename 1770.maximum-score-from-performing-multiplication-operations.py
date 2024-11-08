#
# @lc app=leetcode id=1770 lang=python3
#
# [1770] Maximum Score from Performing Multiplication Operations
#
from typing import *

# @lc code=start
class Solution:
    '''
    # Solution 1: Memoized DFS (top-down 2D DP)
    # T: O(n * m)
    # S: O(n * m) after state compression
    def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:
        n = len(nums)
        m = len(multipliers)

        # memo = [[[None] * m for _ in range(n)] for _ in range(n)]
        memo = [[None] * m for _ in range(n)]

        # def dfs(i, j, k):
        def dfs(i, k):
            # if k == m or i > j:
            if k == m or i == n:
                return 0
            
            # cached = memo[i][j][k]
            cached = memo[i][k]
            if cached is not None:
                return cached
            
            # Before state compression:
            # ans = max(nums[i] * mult[k] + dfs(i + 1, j, k + 1),
            #           nums[j] * mult[k] + dfs(i, j - 1, k + 1))

            j = n - 1 - (k - i)
            ans = max(
                    nums[i] * multipliers[k] + dfs(i + 1, k + 1),
                    nums[j] * multipliers[k] + dfs(i, k + 1))

            # memo[i][j][k] = ans
            memo[i][k] = ans

            return ans
        
        # return dfs(0, n - 1, 0)
        return dfs(0, 0)
    '''
    
    # Solution 2: bottom-up 2D DP
    # T: O(m ^ 2) because m has to be no larger than n
    # S: O(m ^ 2)
    def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:
        n = len(nums)
        m = len(multipliers)

        # dp[k][l] means max score for picking numbers from nums[l:] and then multiply with multipliers[k:]
        dp = [[float('-inf')] * (m + 1) for _ in range(m + 1)]
        dp[-1] = [0] * (m + 1)

        # Iterate backwards to simulate the update order of the top-down memoized DFS above
        for k in range(m - 1, -1, -1):
            for l in range(k, -1, -1):
                r = n - 1 - (k - l)
                dp[k][l] = max(
                        multipliers[k] * nums[l] + dp[k + 1][l + 1],
                        multipliers[k] * nums[r] + dp[k + 1][l])
                
        return dp[0][0]

# @lc code=end

