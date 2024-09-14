#
# @lc app=leetcode id=1768 lang=python3
#
# [1768] Merge Strings Alternately
#

# @lc code=start
class Solution:
    # T: O(m + n)
    # S: O(m + n) immutable str in python
    def mergeAlternately(self, word1: str, word2: str) -> str:
        m = len(word1)
        n = len(word2)

        res = [''] * (m + n)

        i = j = 0
        while i < m and j < n:
            res[i + j] = word1[i]
            i += 1
            res[i + j] = word2[j]
            j += 1

        while i < m:
            res[i + j] = word1[i]
            i += 1

        while j < n:
            res[i + j] = word2[j]
            j += 1

        return ''.join(res)
        
# @lc code=end

