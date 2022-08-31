#
# @lc app=leetcode id=253 lang=python3
#
# [253] Meeting Rooms II
#
from typing import *

# @lc code=start
class Solution:
    # T: O(n * log(n))
    # S: O(n)
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        n = len(intervals)
        starts = [0] * n
        ends = [0] * n
        for i in range(n):
            starts[i] = intervals[i][0]
            ends[i] = intervals[i][1]
        
        starts.sort()
        ends.sort()

        ans = 0
        cur_end_idx = 0
        for i in range(n):
            if starts[i] < ends[cur_end_idx]:
                # overlap, need a new room
                ans += 1
            else:
                # a meeting starts after the end of another meeting, 
                # no overlap, can use the existing room
                cur_end_idx += 1
        return ans
        
# @lc code=end

