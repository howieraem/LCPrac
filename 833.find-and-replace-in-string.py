#
# @lc app=leetcode id=833 lang=python3
#
# [833] Find And Replace in String
#
from typing import *

# @lc code=start
class Solution:
    # Do replacement from right to left to avoid keeping track of indices
    # T: O(n * (log(n) + l)), n := len(indices), l := len(s)
    # S: O(n + l)
    def findReplaceString(self, s: str, indices: List[int], sources: List[str], targets: List[str]) -> str:
        ids = []
        for ii, i in enumerate(indices):
            ids.append((i, ii))
        ids.sort(reverse=True)
        for (i, ii) in ids:
            src = sources[ii]
            dst = targets[ii]
            split_idx = i + len(src)
            if s[i:split_idx] == src:
                s = s[:i] + dst + s[split_idx:]
        return s

# @lc code=end

