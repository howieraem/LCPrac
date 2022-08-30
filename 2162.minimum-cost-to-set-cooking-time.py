#
# @lc app=leetcode id=2162 lang=python3
#
# [2162] Minimum Cost to Set Cooking Time
#
from typing import List

# @lc code=start
class Solution:
    # T: O(1)
    # S: O(1)
    def minCostSetTime(self, startAt: int, moveCost: int, pushCost: int, targetSeconds: int) -> int:
        minutes = targetSeconds // 60
        seconds = targetSeconds % 60
        cur = str(startAt)
        return min(self.get_cost(minutes, seconds, cur, pushCost, moveCost),
                   self.get_cost(minutes - 1, seconds + 60, cur, pushCost, moveCost))   # 60 < secs <= 99 is also possible

    @staticmethod
    def get_cost(mins, secs, cur, pushCost, moveCost):
        if mins > 99 or secs > 99 or mins < 0 or secs < 0:
            # Overflow
            return float('inf')

        # Format the time as required by the microwave
        s = str(mins * 100 + secs)

        ans = 0
        for c in s:
            ans += pushCost
            if c != cur:
                ans += moveCost
                cur = c
        return ans

# @lc code=end

