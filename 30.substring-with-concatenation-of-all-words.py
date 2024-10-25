#
# @lc app=leetcode id=30 lang=python3
#
# [30] Substring with Concatenation of All Words
#
from collections import defaultdict
from typing import *

# @lc code=start
class Solution:
    # Sliding window
    # T: O(n * wl * len(words))
    # S: O(wl * len(words))
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        w_cnts = defaultdict(int)
        for w in words:
            w_cnts[w] += 1
        
        n = len(s)
        wl = len(words[0])  # all words have the same length
        window_sz = len(words) * wl
        
        res = []
        for l in range(n - window_sz + 1):  # n - m + 1 is the number of windows
            # Check if each window is a concatenation of each word in `words`
            if self.is_concat(s[l:l + window_sz], w_cnts, wl):
                res.append(l)

        return res

    @staticmethod
    # Check if the number of each word in window can meet the permutation requirement
    def is_concat(windowed_str: str, w_cnts: dict, wl: int):
        w_cnts_window = defaultdict(int)
        for i in range(0, len(windowed_str), wl):    # len(sub) = m
            word_in_window = windowed_str[i:i + wl]
            required_wc = w_cnts.get(word_in_window, 0)
            if required_wc == 0:
                # word_in_window not appear in word set
                return False
            w_cnts_window[word_in_window] += 1
            if w_cnts_window[word_in_window] > required_wc:
                return False
        return True

# @lc code=end

