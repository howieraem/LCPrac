#
# @lc app=leetcode id=84 lang=python3
#
# [84] Largest Rectangle in Histogram
#
from collections import deque
from typing import List

# @lc code=start
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        # Mono-stack of height indexes 
        # (stack bottom is the index of the smallest height)
        stack = deque()

        # make the solution more elegant (avoid index out of range)
        heights.append(0)
        stack.append(-1)

        ans = 0
        for i, height in enumerate(heights):
            while heights[stack[-1]] > height:
                h = heights[stack.pop()]
                w = i - 1 - stack[-1]
                ans = max(ans, h * w)
            stack.append(i)
        
        # heights.pop()   # remove the auxiliary 0 if needed
        return ans


# @lc code=end

