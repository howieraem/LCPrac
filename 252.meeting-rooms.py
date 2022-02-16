#
# @lc app=leetcode id=252 lang=python3
#
# [252] Meeting Rooms
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n * log(n))
    # S: O(n) worst and O(1) best for sorting (timsort)
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        # Sort by start and then end
        intervals.sort()

        for i in range(1, len(intervals)):
            if intervals[i][0] < intervals[i - 1][1]:
                # Current start is earlier than previous end,
                # overlapping exists. Thus, impossible to 
                # attend all meetings.
                return False

        return True


# @lc code=end

