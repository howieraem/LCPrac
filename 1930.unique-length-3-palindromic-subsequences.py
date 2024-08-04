#
# @lc app=leetcode id=1930 lang=python3
#
# [1930] Unique Length-3 Palindromic Subsequences
#

# @lc code=start
class Solution:
    # Track the first and the last occurrences of each char; then for each char,
    # count unique chars between its first and last occurrences.
    # T: O(len(s) * alpha_size), alpha_size = 26
    # S: O(alpha_size)
    def countPalindromicSubsequence(self, s: str) -> int:
        first = [len(s)] * 26
        last = [0] * 26
        OFFSET = ord('a')

        for i, c in enumerate(s):
            cidx = ord(c) - OFFSET
            first[cidx] = min(first[cidx], i)
            last[cidx] = i

        ans = 0

        for i in range(26):
            if first[i] < last[i]:
                # char appears at least twice, prerequisite of a palindrome
                ans += len(set(s[first[i] + 1:last[i]]))

        return ans

        
# @lc code=end

