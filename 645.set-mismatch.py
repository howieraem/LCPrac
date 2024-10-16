#
# @lc app=leetcode id=645 lang=python3
#
# [645] Set Mismatch
#
from typing import List

# @lc code=start
class Solution:
    # cyclic sort
    # T: O(n)
    # S: O(1)
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        i = 0
        while i < n:
            # i belongs to {0 ... n - 1}
            # nums[i] belongs to {1 ... n}
            correct_idx = nums[i] - 1
            if nums[i] != nums[correct_idx]:
                nums[i], nums[correct_idx] = nums[correct_idx], nums[i]
            else:
                i += 1

        for i in range(n):
            if nums[i] != i + 1:
                return [nums[i], i + 1]
        return []


# @lc code=end

