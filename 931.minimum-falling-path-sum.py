#
# @lc app=leetcode id=931 lang=python3
#
# [931] Minimum Falling Path Sum
#
from typing import List

# @lc code=start
class Solution:
    # 2D DP
    # T: O(m * n)
    # S: O(n)
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        m = len(matrix)
        if m == 0:
            return 0
        n = len(matrix[0])
        if n == 0:
            return 0

        # dp[j] means minimum path sum from first row to the j-th column of the current row
        dp = matrix[0][:]

        for i in range(1, m):
            dp_cur = [0] * n

            for j in range(n):
                dp_cur[j] = matrix[i][j] + min(dp[max(0, j - 1)], dp[j], dp[min(n - 1, j + 1)])

            dp = dp_cur[:]

        return min(dp)

# @lc code=end

