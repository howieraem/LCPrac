#
# @lc app=leetcode id=1822 lang=python3
#
# [1822] Sign of the Product of an Array
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def arraySign(self, nums: List[int]) -> int:
        sign = 1
        # n_neg = 0
        for x in nums:
            if x == 0:
                return 0
            elif x < 0:
                sign = -sign
            # n_neg += (x < 0)
        # return -1 if n_neg & 1 else 1
        return sign

# @lc code=end

