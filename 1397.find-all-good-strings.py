#
# @lc app=leetcode id=1397 lang=python3
#
# [1397] Find All Good Strings
#
from typing import *

# @lc code=start
class Solution:
    # https://leetcode.com/problems/find-all-good-strings/discuss/555591/
    # T: O(n * l * s), l := len(evil), s := 26
    # S: O(n * l)
    def findGoodStrings(self, n: int, s1: str, s2: str, evil: str) -> int:
        MOD = 1000000007
        l = len(evil)
        lps = self.compute_lps(evil)

        # dp[n][l][2][2]
        # dp[i][j][use_left_boundary][use_right_boundary] means the number of good strings of length i,
        # with some substring matching evil[:j + 1], whether to use s1[i] or 'a' as the left boundary, 
        # and whether to use s2[i] or 'z' as the right boundary
        memo = [[[[0, 0], [0, 0]] for _ in range(l)] for _ in range(n)]

        def dfs(i, n_matched_evil_chars, use_left, use_right):
            if n_matched_evil_chars == l:
                return 0  # contains evil substring
            if i == n:
                return 1  # good string
            if memo[i][n_matched_evil_chars][use_left][use_right] != 0:
                return memo[i][n_matched_evil_chars][use_left][use_right]
            
            c_from = s1[i] if use_left else 'a'
            c_to = s2[i] if use_right else 'z'
            ans = 0
            for ci in range(ord(c_from), ord(c_to) + 1):
                c = chr(ci)

                # j means the next match between current string (end at char `c`) and `evil` string
                j = n_matched_evil_chars
                while j > 0 and evil[j] != c:
                    j = lps[j - 1]
                j += (evil[j] == c)
                ans = (ans + dfs(i + 1, j, int(use_left and c == c_from), int(use_right and c == c_to))) % MOD

            memo[i][n_matched_evil_chars][use_left][use_right] = ans
            return ans

        return dfs(0, 0, 1, 1)

    # KMP: For each index in range(0, len(s)), compute the length of the longest prefix 
    # that is also suffix
    @staticmethod
    def compute_lps(s: str) -> List[int]:  
        l = len(s)
        lps = [0] * l
        j = 0
        for i in range(1, l):
            while j > 0 and s[i] != s[j]:
                j = lps[j - 1]
            if s[i] == s[j]:
                j += 1
                lps[i] = j
        return lps

# @lc code=end

