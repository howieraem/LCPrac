#
# @lc app=leetcode id=830 lang=python3
#
# [830] Positions of Large Groups
#
from typing import *

# @lc code=start
class Solution:
    # two pointers
    # T: O(n)
    # S: O(1)
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        K = 3
        res = []
        i = 0
        while i < len(s):
            c = s[i]
            j = i
            while j + 1 < len(s) and s[j + 1] == c:
                j += 1
            
            if j - i + 1 >= K:
                res.append([i, j])
            
            i = j + 1
        
        return res

# @lc code=end

