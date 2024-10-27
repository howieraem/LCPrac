#
# @lc app=leetcode id=1288 lang=python3
#
# [1288] Remove Covered Intervals
#
from typing import List

# @lc code=start
class Solution:
    # Sorting + Greedy + Interval
    # T: O(n * log(n))
    # S: O(n) timsort
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        if len(intervals) == 0:
            return intervals

        # Sort by start time ASC and if tie end time DESC
        intervals.sort(key=lambda interval: (interval[0], -interval[1]))
        
        ans = 1
        # res = []
        _, cur_end = intervals[0]
        for i in range(1, len(intervals)):
            _, e = intervals[i]
            if e > cur_end:
                ans += 1
                # res.append([cur_start, cur_end])
                cur_end = e
        
        # don't forget the last one
        # res.append([cur_start, cur_end])

        return ans  

# @lc code=end

