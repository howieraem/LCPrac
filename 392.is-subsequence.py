#
# @lc app=leetcode id=392 lang=python3
#
# [392] Is Subsequence
#

# @lc code=start
class Solution:
    # T: O(max(len(s), len(t)))
    # S: O(1)
    def isSubsequence(self, s: str, t: str) -> bool:
        i = 0
        j = 0
        m = len(s)
        n = len(t)

        while i < m and j < n:
            i += int(s[i] == t[j])
            j += 1

        return i == m
        
# @lc code=end

