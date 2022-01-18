#
# @lc app=leetcode.cn id=452 lang=python3
#
# [452] 用最少数量的箭引爆气球
#

# @lc code=start
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if not points:
            return 0
        points.sort(key=lambda x: x[1])
        cnt = 1
        pre = points[0][1]
        for balloon in points:
            if balloon[0] > pre:
                pre = balloon[1]
                cnt += 1
        return cnt

# @lc code=end

