#
# @lc app=leetcode id=647 lang=python3
#
# [647] Palindromic Substrings
#

# @lc code=start
class Solution:
    # for each char, try to expand on both sides to form palindromes
    # T: O(n ^ 2)
    # S: O(1)
    def countSubstrings(self, s: str) -> int:
        self.ans = 0
        for i in range(len(s)):
            self.expand_palindrome(s, i, i)  # odd length
            self.expand_palindrome(s, i, i + 1)  # even length
        return self.ans

    def expand_palindrome(self, s: str, l: int, r: int) -> int:
        while l >= 0 and r < len(s) and s[l] == s[r]:
            self.ans += 1
            l -= 1
            r += 1

# @lc code=end

