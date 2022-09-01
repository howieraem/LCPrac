#
# @lc app=leetcode id=759 lang=python3
#
# [759] Employee Free Time
#
import heapq

class Interval:
    def __init__(self, start: int = None, end: int = None):
        self.start = start
        self.end = end

# @lc code=start
"""
# Definition for an Interval.
class Interval:
    def __init__(self, start: int = None, end: int = None):
        self.start = start
        self.end = end
"""

class Solution:
    # Optimal solution: don't sort all intervals, as each employee's intervals are sorted
    # T: O(n * log(k)), n := total number of intervals, k := the number of employees
    # S: O(k)
    def employeeFreeTime(self, schedule: '[[Interval]]') -> '[Interval]':
        min_heap = []
        for i in range(len(schedule)):
            # The last elem in tuple is the next idx of interval for the employee
            heapq.heappush(min_heap, (schedule[i][0].start, schedule[i][0].end, i, 1))

        end = min_heap[0][1]
        res = []
        while len(min_heap):
            new_start, new_end, employee_i, employee_next_interval_i = heapq.heappop(min_heap)
            if new_start <= end:
                # intervals overlap, merge them
                end = max(end, new_end)
            else:
                # no overlap, create the free time interval
                res.append(Interval(end, new_start))
                end = new_end  # IMPORTANT

            if employee_next_interval_i < len(schedule[employee_i]):
                # process next interval for the current employee
                next_interval = schedule[employee_i][employee_next_interval_i]
                heapq.heappush(min_heap, (next_interval.start, next_interval.end, employee_i, employee_next_interval_i + 1))

        return res

# @lc code=end

