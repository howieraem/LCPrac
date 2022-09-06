#
# @lc app=leetcode id=2068 lang=python3
#
# [2068] Check Whether Two Strings are Almost Equivalent
#

# @lc code=start
class Solution:
    # T: O(n + s)
    # S: O(s)
    def checkAlmostEquivalent(self, word1: str, word2: str) -> bool:
        cnts = [0] * 26
        for c1, c2 in zip(word1, word2):
            cnts[ord(c1) - ord('a')] += 1
            cnts[ord(c2) - ord('a')] -= 1
        
        return all(abs(cnt) <= 3 for cnt in cnts)

# @lc code=end

