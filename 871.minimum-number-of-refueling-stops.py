#
# @lc app=leetcode id=871 lang=python3
#
# [871] Minimum Number of Refueling Stops
#
import heapq
from typing import List

# @lc code=start
class Solution:
    # Greedy
    # T: O(n * log(n))
    # S: O(n)
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        if startFuel >= target: # trivial
            return 0

        n = len(stations)
        pq = []  # negate elements to simulate a max heap
        reachable = startFuel
        i = 0
        ans = 0
        while reachable < target:
            while i < n and stations[i][0] <= reachable:
                heapq.heappush(pq, -stations[i][1])
                i += 1
            
            if not len(pq):
                # Run out of stations
                return -1
            
            # Always refuel from the station with the greatest fuel.
            # Note that we can still refuel even if fuel tank is not empty.
            reachable += -heapq.heappop(pq)
            ans += 1
        
        return ans

# @lc code=end

