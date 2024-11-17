#
# @lc app=leetcode id=354 lang=python3
#
# [354] Russian Doll Envelopes
#
from typing import List

# @lc code=start
class Solution:
    # Sorting + Binary search + Greedy?
    # T: O(n * log(n))
    # S: O(n)
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        # sort by width ASC then by height DESC
        envelopes.sort(key=lambda e: (e[0], -e[1]))

        # After sorting, the problem is reduced to finding the
        # length of the longest increasing subsequence (LIS) 
        # of the heights. Widths of the corresponding height 
        # subsequence are always increasing. 
        # heights_lis is sorted, so use greedy + binary search (leftmost)
        # to find where to overwrite in the LIS. More explanation: 
        # https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326308
        heights_lis = [envelopes[0][1]]   # intermediate result is always sorted ASC
        for i in range(1, len(envelopes)):
            h = envelopes[i][1]
            if h > heights_lis[-1]:
                # append if h is greater than all numbers currently in the LIS
                heights_lis.append(h)
            else:
                # When new number h is not greater than the last element of the LIS, 
                # do binary search to find the smallest element >= h in LIS, and 
                # replace with h
                l, r = 0, len(heights_lis)
                while l < r:
                    m = l + ((r - l) >> 1)
                    if heights_lis[m] < h:
                        l = m + 1
                    else:
                        r = m
                heights_lis[l] = h

                # If using built-in function:
                # idx = bisect.bisect_left(heights_lis, h)
                # heights_lis[idx] = h
        return len(heights_lis)

# @lc code=end

