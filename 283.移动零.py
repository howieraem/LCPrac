#
# @lc app=leetcode.cn id=283 lang=python3
#
# [283] 移动零
#

# @lc code=start
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums) < 2:
            return
        j = 0
        for i, num in enumerate(nums):
            if num != 0:
                '''
                if i != j:
                    # swap
                    nums[i], nums[j] = nums[j], nums[i]
                '''
                if i > j:
                    nums[j] = nums[i]
                    nums[i] = 0
                j += 1


# @lc code=end
