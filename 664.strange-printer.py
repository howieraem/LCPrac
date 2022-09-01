#
# @lc app=leetcode id=664 lang=python3
#
# [664] Strange Printer
#
import re

# @lc code=start
class Solution:
    # T: O(n ^ 3)
    # S: O(n ^ 2)
    def strangePrinter(self, s: str) -> int:
        # Optimization: remove consecutive same characters
        # https://leetcode.com/problems/strange-printer/discuss
        s = re.sub(r'(.)\1*', r'\1', s)

        n = len(s)
        if n <= 1:
            return n

        # dp[i][j] means the min. steps to print s[i:j+1].
        # Initialize all entries to n as we are finding the minimum below.
        dp = [[n] * n for _ in range(n)]
        for i in range(n):
            # base cases
            dp[i][i] = 1

        for r in range(n):
            for l in range(r, -1, -1):
                for k in range(l, r):  # print at k
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] - (s[k] == s[r]))

        return dp[0][n - 1]

# @lc code=end

