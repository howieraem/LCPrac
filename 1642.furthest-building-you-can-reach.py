#
# @lc app=leetcode id=1642 lang=python3
#
# [1642] Furthest Building You Can Reach
#
import heapq
from typing import *

# @lc code=start
class Solution:
    # Strategy: use bricks for the smaller height differences, and 
    # ladders for the larger height differences.
    # T: O(n * log(n))
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        n = len(heights)
        min_heap = []  # pq of height differences
        for i in range(n - 1):
            dif = heights[i + 1] - heights[i]
            if dif > 0:
                heapq.heappush(min_heap, dif)
            if len(min_heap) > ladders:
                bricks -= heapq.heappop(min_heap)
            if bricks < 0:
                # Bricks used up
                return i
        return n - 1

# @lc code=end

