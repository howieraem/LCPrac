#
# @lc app=leetcode id=875 lang=python3
#
# [875] Koko Eating Bananas
#
from typing import *

# @lc code=start
class Solution:
    # Idea: binary search the leftmost (least possible) speed of eating
    # T: O(len(piles) * log(max(piles)))
    # S: O(1)
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        # find the range for binary search
        l = 1           # minimum is the smallest positive int
        r = max(piles)  # maximum speed is the largest pile (finish in 1 hour)

        def can_finish(cur_speed):
            t = 0
            for pile in piles:
                # t += math.ceil(pile / cur_speed)
                t += pile // cur_speed + (pile % cur_speed > 0)
                if t > h:
                    return False
            return True

        while l <= r:
            m = l + ((r - l) >> 1)
            if can_finish(m):
                r = m - 1
            else:
                l = m + 1

        '''
        # Alternatively
        while l < r:
            m = l + ((r - l) >> 1)
            if can_finish(m):
                r = m
            else:
                l = m + 1
        '''
        
        return l
        
# @lc code=end

