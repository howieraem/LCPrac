#
# @lc app=leetcode.cn id=63 lang=python3
#
# [63] 不同路径 II
#
from typing import List

# @lc code=start
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if obstacleGrid[0][0]:
            return 0
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        dp = [[0]*n for _ in range(m)]
        dp[0][0] = 1
        for i in range(0, m):
            for j in range(0, n):
                if obstacleGrid[i][j]:
                    continue
                if i or j:  # not at origin
                    left = 0 if not i else dp[i-1][j]
                    top = 0 if not j else dp[i][j-1]
                    dp[i][j] = left+top
        return dp[-1][-1]

# @lc code=end
s = Solution()
print(s.uniquePathsWithObstacles([[0, 0], [1, 1], [0, 0]]))
