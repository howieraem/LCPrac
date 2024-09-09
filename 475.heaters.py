#
# @lc app=leetcode id=475 lang=python3
#
# [475] Heaters
#
from typing import List

# @lc code=start
class Solution:
    # T: O(m * log(m) + n * log(n)), m := len(houses), n := len(heaters)
    # S: O(m + n) sorting
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort()
        heaters.sort()

        ans = 0

        # Find the nearest heater for each house, by comparing 
        # the next heater with the current heater
        i = 0
        n = len(heaters)
        for h in houses:
            while i + 1 < n and abs(heaters[i] - h) >= abs(heaters[i + 1] - h):
                # Move the heater rightwards if it is closer to the given house
                i += 1
            ans = max(ans, abs(heaters[i] - h))
        return ans

# @lc code=end

