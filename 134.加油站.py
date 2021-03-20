#
# @lc app=leetcode.cn id=134 lang=python3
#
# [134] 加油站
#

# @lc code=start
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        """Greedy algorithm."""
        n = len(gas)
        total_tank, curr_tank = 0, 0
        starting_station = 0
        for i in range(n):
            diff = gas[i] - cost[i]
            total_tank += diff
            curr_tank += diff
            # If one couldn't get here, any steps before will be invalid.
            if curr_tank < 0:
                # Pick up the next station as the starting one.
                starting_station = i + 1
                # Start with an empty tank.
                curr_tank = 0
        # Finally, check the fundamental constraint `sum(gas) >= sum(cost)`. If this satisfies, there
        # must be (at least) one solution, and vice versa.
        return starting_station if total_tank >= 0 else -1

# @lc code=end

