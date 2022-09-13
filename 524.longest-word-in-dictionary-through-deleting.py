#
# @lc app=leetcode id=524 lang=python3
#
# [524] Longest Word in Dictionary through Deleting
#
from typing import *

# @lc code=start
class Solution:
    # Find the longest word in dictionary which is a subsequence of s 
    # and with the smallest lexicographical order
    # T: O(len(s) * sum(len(w) for w in dictionary))
    # S: O(1)
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        res = ""
        for w in dictionary:
            wi = 0
            is_subseq = False
            for c in s:
                wi += w[wi] == c
                if wi == len(w):
                    is_subseq = True
                    break
            if not is_subseq:
                continue
            if len(w) > len(res) or (len(w) == len(res) and w < res):
                res = w
        return res


# @lc code=end

