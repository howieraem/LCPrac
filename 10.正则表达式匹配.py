#
# @lc app=leetcode.cn id=10 lang=python3
#
# [10] 正则表达式匹配
#

# @lc code=start
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        dp = [[False] * (n + 1) for _ in range(m + 1)]  # add 1 to consider empty strings
        dp[0][0] = True
        for i in range(m + 1):
            for j in range(1, n + 1):
                if p[j - 1] == '*':
                    dp[i][j] |= dp[i][j - 2]
                    if self.chars_match(s, p, i, j - 1):
                        dp[i][j] |= dp[i - 1][j]
                else:
                    if self.chars_match(s, p, i, j):
                        dp[i][j] |= dp[i - 1][j - 1]
        return dp[m][n]
        
    @staticmethod
    def chars_match(s, p, i, j):
        if not i:   # i == 0
            return False
        return s[i - 1] == p[j - 1] or p[j - 1] == '.'

# @lc code=end
