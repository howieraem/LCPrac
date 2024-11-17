#
# @lc app=leetcode id=587 lang=python3
#
# [587] Erect the Fence
#
from typing import *

# @lc code=start
class Solution:
    # Math + geometry
    # convex hull
    # T: O(n * log(n))
    # S: O(n)
    def outerTrees(self, trees: List[List[int]]) -> List[List[int]]:
        points = sorted((t[0], t[1]) for t in trees)  # sort by x ASC and if x equal then y ASC

        # check if points are in the upper or lower convex hull
        # https://assets.leetcode.com/users/images/d65bc1be-3d71-47ed-93ac-aac395c8ab22_1630671371.658808.png
        def cmp(p1, p2, p3):
            x1, y1 = p1
            x2, y2 = p2            
            x3, y3 = p3
            return (y3 - y2) * (x2 - x1) - (y2 - y1) * (x3 - x2)

        lower = []
        upper = []
        for point in points:
            # https://assets.leetcode.com/users/images/4ae30ac4-6e6f-47fa-9528-7f725735cbbf_1630671725.490843.png
            while len(lower) >= 2 and cmp(lower[-2], lower[-1], point) > 0:
                lower.pop()
            while len(upper) >= 2 and cmp(upper[-2], upper[-1], point) < 0:
                upper.pop()
            
            lower.append(point)
            upper.append(point)

        return list(set(lower + upper))

# @lc code=end

