#
# @lc app=leetcode id=471 lang=python3
#
# [471] Encode String with Shortest Length
#

# @lc code=start
class Solution:
    # T: O(n ^ 3)
    # S: O(n ^ 2)
    def encode(self, s: str) -> str:
        n = len(s)
        if n <= 4:  # encoding will not shorten if length <= 4
            return s

        # dp[i][j] is the answer for s[i:j+1]
        dp = [[""] * n for _ in range(n)]
        for length in range(1, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                substr = s[i:j + 1]
                dp[i][j] = substr  # base case
                if length <= 4:  # encoding will not shorten if length <= 4
                    continue

                for k in range(i, j):
                    if len(dp[i][j]) > len(dp[i][k]) + len(dp[k + 1][j]):
                        dp[i][j] = dp[i][k] + dp[k + 1][j]

                pattern = self.get_longest_pattern(substr)
                if len(pattern) == len(substr):
                    continue
                # pattern should be the same as dp[i][i + len(pattern) - 1]
                abbr = str(len(substr) // len(pattern)) + '[' + dp[i][i + len(pattern) - 1] + ']'
                if len(abbr) < len(substr):
                    dp[i][j] = abbr

        return dp[0][n - 1]

    # Using built-in function
    @staticmethod
    def get_longest_pattern(s: str) -> str:
        pos = (s + s).find(s, 1)  # find the index of first occurrence of s starting from (s + s)[1:]
        if pos >= len(s):
            return s
        return s[:pos]

    '''
    # KMP
    # https://www.geeksforgeeks.org/find-given-string-can-represented-substring-iterating-substring-n-times/
    # T: O(n)
    # S: O(n)
    @staticmethod
    def get_longest_pattern(s: str) -> str:
        if not s:
            return s
        n = len(s)
        lpps = [0] * n  # length of longest proper prefix-suffix
        i = 0
        j = 1
        while j < n:
            if s[i] == s[j]:
                i += 1
                lpps[j] = i
                j += 1
            else:
                if i != 0:
                    i = lpps[i - 1]
                else:
                    lpps[j] = 0
                    j += 1

        # lpps[-1] is the length of the longest suffix which is also
        # the prefix of s.
        # If there exist a suffix which is also prefix and
        # the length of the remaining substring divides total
        # length, then str[0:n - suf_len] is the substring that
        # repeats n / (n - suf_len) times. 
        # n - suf_len is the pattern's length.
        pattern_len = n - lpps[-1]
        if pattern_len != n and n % pattern_len == 0:
            return s[:pattern_len]
        return s
    '''

# @lc code=end

