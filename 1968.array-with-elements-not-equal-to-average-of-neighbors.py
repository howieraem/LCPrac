#
# @lc app=leetcode id=1968 lang=python3
#
# [1968] Array With Elements Not Equal to Average of Neighbors
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        n = len(nums)

        # When an element is the avg of its neighbors,
        # two cases:
        # 1. nums[i - 1] < nums[i] < nums[i + 1]
        # 2. nums[i - 1] > nums[i] > nums[i + 1]
        # So just swap nums[i] and nums[i + 1] to break any patterns like above

        for i in range(1, n - 1):
            x = nums[i - 1]
            y = nums[i]
            z = nums[i + 1]
            if x < y < z or x > y > z:
                nums[i], nums[i + 1] = nums[i + 1], nums[i]

        return nums
        

# @lc code=end

