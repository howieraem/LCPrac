#
# @lc app=leetcode id=189 lang=python3
#
# [189] Rotate Array
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        N = len(nums)
        k %= N   # if k >= N, avoid unnecessary rotations

        # reverse entire array
        self.reverse(nums, 0, N - 1)

        # reverse nums[:k]
        self.reverse(nums, 0, k - 1)

        # reverse nums[k:]
        self.reverse(nums, k, N - 1)

    def reverse(self, nums: List[int], l: int, r: int) -> None:
        while l < r:
            nums[l], nums[r] = nums[r], nums[l]
            l += 1
            r -= 1
        
# @lc code=end

