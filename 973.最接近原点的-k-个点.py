#
# @lc app=leetcode.cn id=973 lang=python3
#
# [973] 最接近原点的 K 个点
#
import math

# @lc code=start
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        points.sort(key=lambda p: math.pow(p[0], 2) + math.pow(p[1], 2))
        return points[:k]

# @lc code=end

