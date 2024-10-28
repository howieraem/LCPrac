#
# @lc app=leetcode id=983 lang=python3
#
# [983] Minimum Cost For Tickets
#
from collections import deque
from typing import *

# @lc code=start
class Solution:
    # Queue simulation + DP
    # T: O(n)
    # S: O(n)
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        past7 = deque()  # queues of (day within the past 7-d window, cost with last 7-d pass)
        past30 = deque()  # queues of (day within the past 30-d window, cost with last 30-d pass)
        cur_cost = 0

        # keep track of travel days
        for d in days:
            # remove expired tickets
            while len(past7) > 0 and past7[0][0] <= d - 7:
                past7.popleft()
            while len(past30) > 0 and past30[0][0]<= d - 30:
                past30.popleft()

            past7.append((d, cur_cost + costs[1]))
            past30.append((d, cur_cost + costs[2]))

            cur_cost = min(cur_cost + costs[0], past7[0][1], past30[0][1])
        
        return cur_cost

# @lc code=end

