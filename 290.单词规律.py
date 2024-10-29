#
# @lc app=leetcode.cn id=290 lang=python3
#
# [290] 单词规律
#

# @lc code=start
class Solution:
    # hash maps
    # T: O(n)
    # S: O(n)
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        if len(words) != len(pattern):
            return False

        p2w = dict()   # k: pattern char, v: word
        w2p = dict()   # k: word, v: pattern char

        for c, word in zip(pattern, words):
            if p2w.get(c, None) != word or w2p.get(word, None) != c:
                return False
        
            p2w[c] = word
            w2p[word] = c
        
        return True
        
# @lc code=end

