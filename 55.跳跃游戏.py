#
# @lc app=leetcode.cn id=55 lang=python3
#
# [55] 跳跃游戏
#
from typing import List

# @lc code=start
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        """Solution: greedy"""
        n, rightmost = len(nums), 0
        for i in range(n):
            if i <= rightmost:   # the jump can reach at least ith location
                # if we have reached the ith location, we can then reach i+nums[i] location 
                rightmost = max(rightmost, i + nums[i])
                if rightmost >= n - 1:
                    return True
        return False


# @lc code=end
# s = Solution()
# print(s.canJump([3, 2, 1, 0, 4]))
