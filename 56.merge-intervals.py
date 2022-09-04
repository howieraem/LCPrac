#
# @lc app=leetcode id=56 lang=python3
#
# [56] Merge Intervals
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n * log(n))
    # S: O(n) timsort space complexity
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # Sort by start time and then end time, both ASC.
        # Sort by start time only also works.
        intervals.sort()

        res = []
        cur_start, cur_end = intervals[0]
        for i in range(len(intervals)):
            start, end = intervals[i]
            if start > cur_end:
                # No overlap, start a new interval
                res.append([cur_start, cur_end])
                cur_start, cur_end = start, end
            elif end > cur_end:
                # Left side overlap and right side no overlap, 
                # so extend the current interval
                cur_end = end
            # else [start, end] is a subset of [cur_start, cur_end], do nothing
        
        # Don't forget the last interval
        res.append([cur_start, cur_end])

        return res
        
# @lc code=end

