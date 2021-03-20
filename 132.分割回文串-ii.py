#
# @lc app=leetcode.cn id=132 lang=python3
#
# [132] 分割回文串 II
#

# @lc code=start
class Solution:
    def minCut(self, s: str) -> int:
        """Code modified from question [131]."""
        # if not s:
        #     return 0
        length = len(s)

        # `dp[i][j]` indicates whether `s[i:j+1]` is a palindrome.
        dp = [[False]*length for _ in range(length)]

        # `dp_n_cuts[i]` means the minimum number of palindrome partitions for `s[:i+1]`
        dp_n_cuts = [0]*length

        for right in range(length):
            tmp = float('inf')
            for left in range(right + 1):
                if s[right] == s[left] and (right - left <= 2 or dp[left + 1][right - 1]):
                    dp[left][right] = True
                    tmp = 0 if not left else min(tmp, dp_n_cuts[left-1]+1)
            dp_n_cuts[right] = tmp
        return dp_n_cuts[-1]

# @lc code=end

