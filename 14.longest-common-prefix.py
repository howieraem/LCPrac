#
# @lc app=leetcode id=14 lang=python3
#
# [14] Longest Common Prefix
#
from typing import List

# @lc code=start
class Solution:
    '''
    # Solution 1: Start from the first word. Check prefix of following words, and stop early if no prefix found 
    # T: O(n * m), n := len(strs), m := max(len(s) for s in strs)
    # S: O(1), or O(m) if string immutable due to substring operation
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ans = strs[0]
        for i in range(1, len(strs)):
            j = 0
            max_len = min(len(strs[i]), len(ans))
            while j < max_len and strs[i][j] == ans[j]:
                j += 1
            ans = ans[:j]
            if not ans:
                return ans
        return ans
    '''

    # Solution 2: Sort lexicographically, and then just check the first and the last words
    # Faster than solution 1 if log(n * m) < m
    # T: O(n * log(n * m) + m), n := len(strs), m := max(len(s) for s in strs)
    # S: O(n * m)
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        strs = sorted(strs)
        ans = []

        for i in range(min(len(strs[0]), len(strs[-1]))):
            if strs[0][i] != strs[-1][i]:
                # stop early if mismatched
                return "".join(ans)
            ans.append(strs[0][i])

        return "".join(ans)

# @lc code=end

