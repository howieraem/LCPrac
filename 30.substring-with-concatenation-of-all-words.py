#
# @lc app=leetcode id=30 lang=python3
#
# [30] Substring with Concatenation of All Words
#
from collections import defaultdict
from typing import *

# @lc code=start
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        w_cnts = defaultdict(int)
        for w in words:
            w_cnts[w] += 1
        
        n = len(s)
        l = len(words)
        wl = len(words[0])  # all words have the same length
        m = l * wl  # window size (fixed)
        res = []

        for i in range(n - m + 1):  # n - m + 1 is the number of windows
            sub = s[i:i + m]

            # Check if each window is a concatenation of each word in `words`
            if self.is_concat(sub, w_cnts, wl):
                res.append(i)

        return res

    @staticmethod
    def is_concat(sub: str, w_cnts: dict, wl: int):
        w_cnts_sub = defaultdict(int)
        for i in range(0, len(sub), wl):    # len(sub) = m
            w = sub[i:i + wl]
            if w not in w_cnts:
                return False
            w_cnts_sub[w] += 1
            if w_cnts_sub[w] > w_cnts[w]:
                return False
        return True

# @lc code=end

