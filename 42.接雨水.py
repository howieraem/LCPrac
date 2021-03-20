#
# @lc app=leetcode.cn id=42 lang=python3
#
# [42] 接雨水
#

# @lc code=start
class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        max_left = max_right = 0
        left, right = 1, len(height)-2
        for i in range(1, len(height)-1):
            if height[left-1] < height[right+1]:
                # shift left pointer
                max_left = max(max_left, height[left-1])
                if max_left > height[left]:
                    ans += (max_left - height[left])
                left += 1
            else:
                # shift right pointer
                max_right = max(max_right, height[right+1])
                if max_right > height[right]:
                    ans += (max_right - height[right])
                right -= 1
        return ans


# @lc code=end

