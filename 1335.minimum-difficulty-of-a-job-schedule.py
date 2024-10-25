#
# @lc app=leetcode id=1335 lang=python3
#
# [1335] Minimum Difficulty of a Job Schedule
#
from typing import List

# @lc code=start
class Solution:
    # Solution 1: 2D DP solution
    # T: O(n * n * d)
    # S: O(n * d)
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        if d > n:
            return -1
        
        # dp[i][j] means the min difficulty sum for the first i days with j jobs
        dp = [[0] * n for _ in range(d)]
        
        # base cases
        dp[0][0] = jobDifficulty[0]
        for j in range(1, n):
            dp[0][j] = max(dp[0][j - 1], jobDifficulty[j])
        
        # Cut jobDifficulty into d non-empty sub-arrays
        # i the index of the last cut and j the number of remaining cuts
        for i in range(1, d):
            for j in range(i, n):
                local_max = jobDifficulty[j]
                dp[i][j] = float('inf')
                for k in range(j, i - 1, -1):
                    local_max = max(local_max, jobDifficulty[k])
                    dp[i][j] = min(dp[i][j], dp[i - 1][k - 1] + local_max)

        return dp[d - 1][n - 1]

    '''
    # Solution 2: 1D DP and mono-stack
    # T: O(n * d)
    # S: O(n)
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        if d > n:
            return -1
        
        # state compressed
        dp = [float('inf')] * n
        dp2 = [0] * n

        for i in range(d):
            stack = []   # stores indices of job difficulties in descending order

            for j in range(i, n):
                dp2[j] = dp[j - 1] + jobDifficulty[j] if j > 0 else jobDifficulty[j]
                while len(stack) > 0 and jobDifficulty[stack[-1]] <= jobDifficulty[j]:
                    k = stack.pop()
                    # explanation: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/solutions/490316/java-c-python3-dp-o-nd-solution/comments/958543
                    dp2[j] = min(dp2[j], dp2[k] - jobDifficulty[k] + jobDifficulty[j])
                if len(stack) > 0:
                    dp2[j] = min(dp2[j], dp2[stack[-1]])
                stack.append(j)
            
            dp, dp2 = dp2, dp   # state compression, rolling update

        return dp[n - 1]
    '''
        
# @lc code=end

