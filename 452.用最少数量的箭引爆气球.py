#
# @lc app=leetcode.cn id=452 lang=python3
#
# [452] 用最少数量的箭引爆气球
#
from typing import List

# @lc code=start
class Solution:
    # Interval + Sorting + Greedy
    # T: O(n * log(n))
    # S: O(n) timsort
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if len(points) == 0:
            return 0
        points.sort(key=lambda x: x[1])  # sort by interval ends

        ans = 1
        pre_end = points[0][1]
        for cur_start, cur_end in points:
            if cur_start > pre_end:
                pre_end = cur_end
                ans += 1
        
        return ans

# @lc code=end

