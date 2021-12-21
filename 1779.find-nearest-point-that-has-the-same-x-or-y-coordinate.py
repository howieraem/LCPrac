#
# @lc app=leetcode id=1779 lang=python3
#
# [1779] Find Nearest Point That Has the Same X or Y Coordinate
#
from typing import *

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        dist = float('inf')
        ans = -1
        for i, (px, py) in enumerate(points):
            dx = abs(px - x)
            dy = abs(py - y)
            if not (dx and dy):     # either is 0
                cur_dist = dx or dy     # get the non-zero one (or zero if both are zero)
                if cur_dist < dist:
                    dist = cur_dist
                    ans = i
        return ans

# @lc code=end

