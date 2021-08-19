#
# @lc app=leetcode.cn id=62 lang=python3
#
# [62] 不同路径
#
import math

# @lc code=start
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        """Solution with O(N) storage."""
        dp = [0 for _ in range(m)]
        dp[0] = 1
        for _ in range(n):
            for j in range(1, m):
                dp[j] += dp[j-1]
        return dp[-1]

    def uniquePaths(self, m: int, n: int) -> int:
        """找规律，排列组合：C(m+1, m+n-2)"""
        return int(math.factorial(m+n-2)/math.factorial(m-1)/math.factorial(n-1))

    """
    original solution, space O(m*n):

    def uniquePaths(self, m: int, n: int) -> int:    
        dp = [[1]*n] + [[1]+[0] * (n-1) for _ in range(m-1)]
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[-1][-1]
    """

# @lc code=end
# s = Solution()
# print(s.uniquePaths(3, 2))
