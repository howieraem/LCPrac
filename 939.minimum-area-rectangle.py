#
# @lc app=leetcode id=939 lang=python3
#
# [939] Minimum Area Rectangle
#
from collections import defaultdict
from typing import List

# @lc code=start
class Solution:
    # T: O(n ^ 2)
    # S: O(n)
    def minAreaRect(self, points: List[List[int]]) -> int:
        n = len(points)

        x_to_y = defaultdict(set)
        for (x, y) in points:
            x_to_y[x].add(y)
        
        INF = float('inf')
        ans = INF
        for i in range(n):
            x1, y1 = points[i]
            for j in range(i + 1, n):
                x2, y2 = points[j]

                if x1 != x2 and y1 != y2:
                    if y1 in x_to_y[x2] and y2 in x_to_y[x1]:
                        # p1 and p2 form a diagonal of a rectangle
                        ans = min(ans, abs(x1 - x2) * abs(y1 - y2))
        return ans if ans < INF else 0       


# @lc code=end

