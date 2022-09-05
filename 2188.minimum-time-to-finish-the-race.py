#
# @lc app=leetcode id=2188 lang=python3
#
# [2188] Minimum Time to Finish the Race
#
import math
from typing import List

# @lc code=start
class Solution:
    '''
    # Original DFS with memo
    # T: O(n * numLaps), n := len(tires)
    # S: O(numLaps)
    def minimumFinishTime(self, tires: List[List[int]], changeTime: int, numLaps: int) -> int:
        # best[i] is the least time we need to finish i laps using a single tire. 
        # For each tire, we try to use it to update the best values.
        INF = float('inf')
        best = [INF] * (numLaps + 1)
        max_laps = 0

        for i in range(len(tires)):
            f, r = tires[i]
            # Init lap 0
            lap_t = f
            tot_t = lap_t

            for lap in range(1, numLaps + 1):
                if lap_t >= f + changeTime:
                    # If using the same tire takes no less time than changing the tire, 
                    # stop further using the current tire
                    break
                max_laps = max(max_laps, lap)
                best[lap] = min(best[lap], tot_t)
                lap_t *= r
                tot_t += lap_t
        
        memo = [INF] * (numLaps + 1)

        def dfs(laps_remain):
            if laps_remain == 0:
                return -changeTime
            if memo[laps_remain] == INF:
                for lap in range(1, min(laps_remain, max_laps) + 1):
                    memo[laps_remain] = min(memo[laps_remain], best[lap] + changeTime + dfs(laps_remain - lap))
            return memo[laps_remain]

        return dfs(numLaps)
    '''

    MAX_CHANGE_TIME = 1e5
    MIN_R = 2

    # Space-optimized: given the maximum changeTime, it turns out there is a upper bound of laps when using the same tire.
    # Given changeTime <= 10^5 and r >= 2, the upper bound will be ceil(log2(10^5)).
    # T: O(n * maxLaps), n := len(tires), maxLaps := ceil(log_minR(maxChangeTime))
    # S: O(maxLaps)
    def minimumFinishTime(self, tires: List[List[int]], changeTime: int, numLaps: int) -> int:
        # best[i] is the least time we need to finish i laps using a single tire. 
        # For each tire, we try to use it to update the best values.
        INF = float('inf')
        max_laps = math.ceil(math.log(self.MAX_CHANGE_TIME) / math.log(self.MIN_R))
        best = [INF] * (max_laps + 1)

        for i in range(len(tires)):
            f, r = tires[i]
            # Init lap 0
            lap_t = f
            tot_t = lap_t

            for lap in range(1, max_laps + 1):
                if lap_t >= f + changeTime:
                    # If using the same tire takes no less time than changing the tire, 
                    # stop further using the current tire
                    break
                best[lap] = min(best[lap], tot_t)
                lap_t *= r
                tot_t += lap_t

        memo = [INF] * (max_laps + 1)

        def dfs(laps_remain):
            if laps_remain == 0:
                return -changeTime
            lap_idx = laps_remain % (max_laps + 1)
            if memo[lap_idx] == INF:
                for lap in range(1, min(laps_remain, max_laps) + 1):
                    memo[lap_idx] = min(memo[lap_idx], best[lap] + changeTime + dfs(laps_remain - lap))
            return memo[lap_idx]

        return dfs(numLaps)

# @lc code=end

