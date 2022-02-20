#
# @lc app=leetcode id=85 lang=python3
#
# [85] Maximal Rectangle
#
from typing import List

# @lc code=start
class Solution:
    # Convert the problem to Q84
    # T: O(m * n)
    # S: O(n)
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        m, n = len(matrix), len(matrix[0])
        heights = [0] * n
        ans = 0

        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '1':
                    heights[j] += 1  # accumulate bar height
                else:
                    heights[j] = 0   # not a valid bar anymore
            ans = max(ans, self.largestRectangleArea(heights))
        return ans

    def largestRectangleArea(self, heights: List[int]) -> int:
        # Mono-stack of height indexes 
        # (stack bottom is the index of the smallest height)
        stack = []

        # make the solution more elegant (avoid index out of range)
        stack.append(-1)
        heights.append(0)

        ans = 0
        for i, height in enumerate(heights):
            while heights[stack[-1]] > height:
                h = heights[stack.pop()]
                w = i - stack[-1] - 1
                ans = max(ans, h * w)
            stack.append(i)
        
        heights.pop()   # remove the auxiliary 0
        return ans

# @lc code=end

