#
# @lc app=leetcode id=163 lang=python3
#
# [163] Missing Ranges
#
from typing import *

# @lc code=start
class Solution:

    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[str]:
        n = len(nums)
        res = []
        if not n:
            res.append(self.range_str(lower, upper))
            return res

        # Constriant: values in nums must be in interval [lower, upper]

        if nums[0] > lower:
            res.append(self.range_str(lower, nums[0] - 1))
        
        for i in range(n - 1):
            if nums[i + 1] - nums[i] > 1:
                res.append(self.range_str(nums[i] + 1, nums[i + 1] - 1))
        
        if nums[n - 1] < upper:
            res.append(self.range_str(nums[n - 1] + 1, upper))

        return res

    @staticmethod
    def range_str(l: int, r: int) -> str:
        return str(l) if l == r else "{}->{}".format(l, r)

# @lc code=end

