#
# @lc app=leetcode id=1109 lang=python3
#
# [1109] Corporate Flight Bookings
#
from typing import *

# @lc code=start
class Solution:
    # Sweeping line algorithm
    # T: O(n)
    # S: O(1) (no extra space required except the output container)
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        res = [0] * n

        # begin and end are 1-indexed
        for begin, end, reserve in bookings:
            res[begin - 1] += reserve
            if end < n:
                # Need to subtract except for the last flight
                res[end] -= reserve

        # At this point, res is an array of reservation changes/differences.
        # To get the total reservations for each flight, need to compute the 
        # prefix sum.

        for i in range(1, n):
            res[i] += res[i - 1]

        return res

# @lc code=end

