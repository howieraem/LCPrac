#
# @lc app=leetcode id=354 lang=python3
#
# [354] Russian Doll Envelopes
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n * log(n))
    # S: O(n)
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        # sort by width ASC then by height DESC
        envelopes.sort(key=lambda e: (e[0], -e[1]))

        # After sorting, the problem is equivalent to finding 
        # the length of the longest increasing subsequence of 
        # the heights
        heights_lis = []
        sz = 0
        for _, h in envelopes:
            if not len(heights_lis) or h > heights_lis[-1]:
                heights_lis.append(h)
                sz += 1
            else:
                # heights_lis is sorted, so use binary search 
                # to find where to overwrite
                # More explanation: https://leetcode.com/problems/longest-increasing-subsequence/discuss/1636162/
                l, r = 0, sz
                while l < r:
                    m = l + ((r - l) >> 1)
                    if heights_lis[m] < h:
                        l = m + 1
                    else:
                        r = m
                heights_lis[l] = h
        return sz

# @lc code=end

