#
# @lc app=leetcode id=448 lang=python3
#
# [448] Find All Numbers Disappeared in an Array
#
from collections import List

# @lc code=start
class Solution:
    # cyclic sort
    # T: O(n)
    # S: O(1)
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
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

        res = []
        for i in range(n):
            if nums[i] != i + 1:
                res.append(i + 1)
        return res

# @lc code=end

