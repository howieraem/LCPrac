#
# @lc app=leetcode.cn id=75 lang=python3
#
# [75] 颜色分类
#
# from typing import List

# @lc code=start
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # 对于所有 idx < p0: nums[idx < p0] = 0
        # curr是当前考虑元素的下标
        p0 = curr = 0
        # 对于所有 idx > p2: nums[idx > p2] = 2
        p2 = len(nums) - 1

        while curr <= p2:
            if nums[curr] == 0:
                nums[p0], nums[curr] = nums[curr], nums[p0]
                p0 += 1
                curr += 1
            elif nums[curr] == 2:
                nums[curr], nums[p2] = nums[p2], nums[curr]
                p2 -= 1
            else:
                curr += 1

# @lc code=end
# s = Solution()
# a = [2,0,2,1,1,0]
# s.sortColors(a)
# print(a)
