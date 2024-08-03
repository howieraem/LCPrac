#
# @lc app=leetcode id=118 lang=python3
#
# [118] Pascal's Triangle
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n ^ 2)
    # S: O(1) excl. output
    def generate(self, numRows: int) -> List[List[int]]:
        dp = [[] for _ in range(numRows)]
        for i in range(numRows):
            dp[i] = [0] * (i + 1)
            dp[i][0] = dp[i][i] = 1
            for j in range(1, i):
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
        return dp


# @lc code=end

