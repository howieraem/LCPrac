#
# @lc app=leetcode id=1499 lang=python3
#
# [1499] Max Value of Equation
#
import heapq
from collections import deque
from typing import *

# @lc code=start
"""
As xi < xj, yi + yj + |xi - xj| = (yi - xi) + (yj + xj)
"""

class Solution:
    """
    # Intuitive: use heap to maximize yi - xi
    # T: O(n * log(n))
    # S: O(n)
    def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:
        # For each pair of (xj, yj), find the maximum yi - xi
        ans = float('-inf')
        max_heap = []  # stores eligible tuples (-(yi - xi), xi), negate to simulate max heap
        for x, y in points:
            while len(max_heap) and max_heap[0][1] < x - k:
                # xj - xi cannot be greater than k
                heapq.heappop(max_heap)
            if len(max_heap):
                ans = max(ans, -max_heap[0][0] + y + x)
            heapq.heappush(max_heap, (x - y, x))
        return ans
    """

    # Optimized: Mono-deque
    # T: O(n)
    # S: O(n)
    def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:
        q = deque()  # deque of tuples (yi - xi, x). deque front yi - xi is always the maximum.
        ans = float('-inf')
        for x, y in points:
            while len(q) and q[0][1] < x - k:
                # xj - xi cannot be greater than k
                q.popleft()
            if len(q):
                ans = max(ans, q[0][0] + y + x)
            while len(q) and q[-1][0] <= y - x:
                q.pop()
            q.append((y - x, x))
        return ans

# @lc code=end

