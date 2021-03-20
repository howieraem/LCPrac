#
# @lc app=leetcode.cn id=290 lang=python3
#
# [290] 单词规律
#

# @lc code=start
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        if len(words) != len(pattern):
            return False

        p2w, w2p = dict(), dict()
        for c, word in zip(pattern, words):
            if (c in p2w and p2w[c] != word) or (word in w2p and w2p[word] != c):
                return False
            p2w[c] = word
            w2p[word] = c
        return True
        
# @lc code=end

