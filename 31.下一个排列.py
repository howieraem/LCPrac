#
# @lc app=leetcode.cn id=31 lang=python3
#
# [31] 下一个排列
#
from typing import List

# @lc code=start
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n < 2:
            return
        idx1 = 0
        for i in range(n-1, 0, -1):
            if nums[i] > nums[i-1]:
                idx1 = i
                break
        if idx1 == n-1:
            nums[idx1], nums[idx1-1] = nums[idx1-1], nums[idx1]
        else:
            self.reverse_inplace(nums, idx1, n-1)   # ensure the next permutation, not just a greater one
            if not idx1:
                return
            for idx2 in range(idx1, n):
                if nums[idx2] > nums[idx1-1]:
                    nums[idx1-1], nums[idx2] = nums[idx2], nums[idx1-1]
                    break
    
    def reverse_inplace(self, nums, start, end):
        mid = (start + end + 1) >> 1
        for k, j in enumerate(range(start, mid)):
            nums[j], nums[end-k] = nums[end-k], nums[j]


# @lc code=end
# s = Solution()
# l = [1, 3, 2]
# s.nextPermutation(l)
# print(l)
