#
# @lc app=leetcode id=881 lang=python3
#
# [881] Boats to Save People
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n * log(n))
    # S: O(n) sorting
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()

        # Greedy: make each boat carry the remaining heaviest and lightest people (two people max)
        l = 0
        r = len(people) - 1
        ans = 0
        while l <= r:
            if people[l] + people[r] <= limit:
                # carry a light person if possible
                l += 1
            # otherwise too heavy, move the right pointer to carry just the heavy person,
            # and get a new boat
            r -= 1
            ans += 1

        return ans
        

# @lc code=end

