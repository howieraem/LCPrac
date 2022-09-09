#
# @lc app=leetcode id=275 lang=python3
#
# [275] H-Index II
#
from typing import *

# @lc code=start
class Solution:
    # T: O(log(n))
    # S: O(1)
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        l = 0
        r = n - 1

        # Search for the 1st (leftmost) index from the sorted array so that 
        # citations[index] >= length(citations) - index
        while l <= r:
            m = l + ((r - l) >> 1)
            d = n - m
            if citations[m] >= d:
                # If citations[m] > n - m, still need to search for a higher h (i.e. lower m)
                r = m - 1
            else:
                l = m + 1
        return n - l
        
# @lc code=end

