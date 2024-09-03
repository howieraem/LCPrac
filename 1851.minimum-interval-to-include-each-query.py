#
# @lc app=leetcode id=1851 lang=python3
#
# [1851] Minimum Interval to Include Each Query
#
import heapq
from typing import List

# @lc code=start
class Solution:
    # T: O(n * log(n) + q * log(q)), n := len(intervals), q := len(queries)
    # S: O(n + q)
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        intervals.sort()
        sorted_qs = sorted(queries)
        min_heap = []   # min heap of (interval_len, interval_end)
        raw_res = {}
        n = len(intervals)

        ii = 0
        for q in sorted_qs:
            # add possible intervals (start <= q)
            while ii < n and intervals[ii][0] <= q:
                l, r = intervals[ii]
                heapq.heappush(min_heap, (r - l + 1, r))
                ii += 1

            # remove irrelevant intervals (end < q)
            while len(min_heap) > 0 and min_heap[0][1] < q:
                heapq.heappop(min_heap)

            # If heap not empty, heap top contains the smallest interval containing q;
            # Otherwise no such interval exists
            raw_res[q] = min_heap[0][0] if len(min_heap) > 0 else -1

        return [raw_res[q] for q in queries]

# @lc code=end

