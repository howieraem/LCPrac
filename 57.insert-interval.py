#
# @lc app=leetcode id=57 lang=python3
#
# [57] Insert Interval
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1) excl. copying intervals
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        N = len(intervals)

        res = []

        i = 0

        # non-overlapping intervals prior to the new interval
        while i < N and intervals[i][1] < newInterval[0]:
            res.append(intervals[i])
            i += 1

        # merge intervals
        while i < N and intervals[i][0] <= newInterval[1]:
            newInterval[0] = min(newInterval[0], intervals[i][0])
            newInterval[1] = max(newInterval[1], intervals[i][1])
            i += 1

        res.append(newInterval)

        # non-overlapping intervals after the new interval
        res.extend(intervals[i:])

        return res


# @lc code=end

