#
# @lc app=leetcode.cn id=11 lang=python3
#
# [11] 盛最多水的容器
#
from typing import List

# @lc code=start
class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        ans = 0
        while l < r:
            area = min(height[l], height[r]) * (r - l)
            ans = max(ans, area)

            # Shift pointer to the lower height to find
            # possibly greater area. Since the area depends on
            # the lower height but not the higher height, shift
            # the higher height closer will surely decrease
            # the area.
            if height[l] <= height[r]:
                l += 1
            else:
                r -= 1
        return ans

    """
    original solution:

    def maxArea(self, height: List[int]) -> int:
        n, ans = len(height), 0
        arr = [[0]*n for _ in range(n)]
        for i in range(n):
            for j in range(i+1, n):
                area = (j-i)*min(height[i], height[j])
                ans = max(area, ans)
        return ans
    """

# @lc code=end
s = Solution()
print(s.maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]))
