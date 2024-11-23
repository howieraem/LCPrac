#
# @lc app=leetcode id=853 lang=python3
#
# [853] Car Fleet
#
from typing import List

# @lc code=start
class Solution:
    # Sorting + mono-stack
    # T: O(n * log(n))
    # S: O(n)
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = [None] * len(position)   # (start_pos, min_t_to_reach_target_ignoring_slower_cars)
        for i, (p, s) in enumerate(zip(position, speed)):
            cars[i] = (p, (target - p) / s)

        cars.sort()  # sort by start pos

        st = []
        for _, t in cars:
            # Mono-stack storing travel time ordered DESC
            # to simulate that faster cars are subject to 
            # slower cars in front
            while len(st) > 0 and st[-1] <= t:
                st.pop()

            st.append(t)

        return len(st)


# @lc code=end

