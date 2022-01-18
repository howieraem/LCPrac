#
# @lc app=leetcode.cn id=218 lang=python3
#
# [218] 天际线问题
#
import heapq
from typing import List

# @lc code=start
class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        """Line Sweep Algorithm: For each building, push the height to heap when the left line is encountered, 
        then pop the height when the right line is encountered."""
        points = []
        for l, r, h in buildings:
            # 左端点通过负数高度来标识，同时适用于标准库中的min heap便相当于max heap
            points.append((l, -h, r))
            points.append((r, h, 0))

        # 将扫描线中的关键点按照points的前两个元素x, y来排序
        points.sort()

        # 堆包含初始元素：0初始高度，`float('inf')`对应无穷右边界
        height_heap = [[0, float('inf')]]    
        res = [[0, 0]]
   
        for x, h, r in points:
            # 关键点：清除扫过的高楼
            while x >= height_heap[0][1]:
                heapq.heappop(height_heap)
            # 左端点入堆
            if h < 0:
                heapq.heappush(height_heap, [h, r])

            # 如果当前最大高度变化，说明是天际线中的关键点
            if res[-1][1] != -height_heap[0][0]:    # 因为高度转为负，实际最高的就在标准库min heap的第一位
                res.append([x, -height_heap[0][0]])
        return res[1:]


# @lc code=end
# a = [
#     [2, 9, 10], [3, 7, 15], [5, 12, 12], [15, 20, 10], [19, 24, 8]
# ]
# print(Solution().getSkyline(a))
