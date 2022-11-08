#
# @lc app=leetcode id=91 lang=python3
#
# [91] Decode Ways
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1) with state compression
    def numDecodings(self, s: str) -> int:
        n = len(s)

        '''
        # Without state compression
        dp = [0] * (n + 1)
        dp[0] = 1   # base case: empty string
        dp[1] = int(s[0] != '0')
        
        for i in range(2, n + 1):
            # dp[i] is 0 if s[i - 1] == '0'
            if '0' < s[i - 1] <= '9':
                dp[i] += dp[i - 1]
            if s[i - 2] == '1' or (s[i - 2] == '2' and s[i - 1] < '7'):
                # 10 <= int(s[i - 2:i]) <= 26
                dp[i] += dp[i - 2]
        return dp[n]
        '''

        # With state compression
        pre2 = 1
        pre1 = int(s[0] != '0')
        if n == 1:
            return pre1

        for i in range(2, n + 1):
            cur = 0
            if '0' < s[i - 1] <= '9':
                cur += pre1
            if s[i - 2] == '1' or (s[i - 2] == '2' and s[i - 1] < '7'):
                cur += pre2

            pre2 = pre1
            pre1 = cur

        return pre1

        # FOLLOW-UP: Print all decodings


# @lc code=end

