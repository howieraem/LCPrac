#
# @lc app=leetcode id=26 lang=python3
#
# [26] Remove Duplicates from Sorted Array
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        i, j = 1, 0
        while i < n:
            if nums[j] != nums[i]:
                j += 1
                nums[j] = nums[i]
            i += 1
        return j + 1

# @lc code=end

