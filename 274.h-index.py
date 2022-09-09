#
# @lc app=leetcode id=274 lang=python3
#
# [274] H-Index
#
from typing import *

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n)
    def hIndex(self, paper_citations: List[int]) -> int:
        n = len(paper_citations)
        cite_cnts = [0] * (n + 1)  # upper bound of h-index is the number of papers
        for cite in paper_citations:
            cite_cnts[min(cite, n)] += 1
        
        paper_cnt = 0
        for h in range(n, -1, -1):
            paper_cnt += cite_cnts[h]
            # If h papers have at least h citations each
            if paper_cnt >= h:
                return h
        return 0
        
# @lc code=end

