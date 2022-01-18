#
# @lc app=leetcode.cn id=85 lang=python3
#
# [85] 最大矩形
#
from typing import List

# @lc code=start
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]:
            return 0
        m, n = len(matrix), len(matrix[0])
        heights = [0]*n
        ans = 0
        # converts the problem to finding the maximum rectangle area
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '1':
                    heights[j] += 1
                else:
                    heights[j] = 0  # reset if there is a 0 between 1's
            ans = max(ans, self.__largestRectangleArea(heights))
        return ans

    @staticmethod
    def __largestRectangleArea(heights: List[int]) -> int:
        """code from question [84]."""
        heights = [0] + heights + [0]
        stack, ans = [], 0
        for i in range(len(heights)):
            while stack and heights[stack[-1]] > heights[i]:
                tmp = stack.pop()
                ans = max(ans, (i - stack[-1] - 1) * heights[tmp])
            stack.append(i)
        return ans

# @lc code=end
