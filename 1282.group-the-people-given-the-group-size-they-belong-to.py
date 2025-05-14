#
# @lc app=leetcode id=1282 lang=python3
#
# [1282] Group the People Given the Group Size They Belong To
#
# from collections import defaultdict
from typing import *

# @lc code=start
class Solution:
    # Hash Map + Greedy
    # T: O(n)
    # S: O(n)
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        # size2group: Dict[int, List[int]] = defaultdict(list)
        size2group = [[] for _ in range(len(groupSizes))]   # max. no. of groups occur when group sizes are all 1
        res = []
        for i, sz in enumerate(groupSizes):
            sz_idx = sz - 1
            size2group[sz_idx].append(i)
            if len(size2group[sz_idx]) == sz:
                # Complete popping up the current group. Create a new one.
                res.append(size2group[sz_idx])
                size2group[sz_idx] = []

        return res

# @lc code=end

