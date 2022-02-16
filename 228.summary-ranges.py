#
# @lc app=leetcode id=228 lang=python3
#
# [228] Summary Ranges
#
from typing import *

# @lc code=start
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        res = []
        n = len(nums)

        j = 0
        for i in range(n):
            if i < n - 1 and nums[i + 1] - nums[i] == 1:
                continue

            if j == i:
                res.append(str(nums[j]))
            else:
                res.append(f"{nums[j]}->{nums[i]}")
            j = i + 1
        
        return res

# @lc code=end

