#
# @lc app=leetcode id=474 lang=python3
#
# [474] Ones and Zeroes
#
from typing import *

# @lc code=start
class Solution:
    # 3D DP
    # T: O(len(strs) * m * n)
    # S: O(m * n)
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        # dp[i][j] means the max subset size with at most i zeros and j ones
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        for s in strs:
            cnt0 = sum(c == '0' for c in s)
            cnt1 = len(s) - cnt0

            for i in range(m, cnt0 - 1, -1):
                for j in range(n, cnt1 - 1, -1):
                    # take or not take the current string into the subset
                    dp[i][j] = max(dp[i][j], 1 + dp[i - cnt0][j - cnt1])

        return dp[m][n]

# @lc code=end

