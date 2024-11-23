#
# @lc app=leetcode id=1436 lang=python3
#
# [1436] Destination City
#
from typing import *

# @lc code=start
class Solution:
    # hash set + basic graph
    # T: O(n)
    # S: O(n)
    def destCity(self, paths: List[List[str]]) -> str:
        starts = set()
        for s, _ in paths:
            starts.add(s)

        for _, e in paths:
            if e not in starts:
                return e
        
        return ""

        
# @lc code=end

