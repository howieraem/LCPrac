#
# @lc app=leetcode.cn id=131 lang=python3
#
# [131] 分割回文串
#
from typing import List

# @lc code=start
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        """Solution with DP code from question [5] longest palindrome. Time complexity O(N^2)."""
        if not s:
            return []
        length = len(s)
        # `dp[i][j]` indicates whether `s[i:j+1]` is a palindrome.
        dp = [[False]*length for _ in range(length)]
        for right in range(length):
            for left in range(right + 1):
                if s[right] == s[left] and (right - left <= 2 or dp[left + 1][right - 1]):
                    # examples of `right - left <= 2`: "aa", "a", etc.
                    dp[left][right] = True

        res = []

        def backtrack(collect, left):
            if left == length:
                res.append(collect[:])
                return
            for right in range(left, length):
                if dp[left][right]:  # if self.isPalindrome(substring):
                    collect.append(s[left:right+1])
                    backtrack(collect, right+1)
                    collect.pop()

        backtrack([], 0)
        return res
    """
    @staticmethod
    def isPalindrome(string):
        n = len(string)
        for i in range(n//2):
            if string[i] != string[n-i-1]:
                return False
        return True
    """

# @lc code=end
# print(Solution().partition('mbmccbc'))
