#
# @lc app=leetcode id=1929 lang=python3
#
# [1929] Concatenation of Array
#
from typing import *

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n)
    def getConcatenation(self, nums: List[int]) -> List[int]:
        n = len(nums)
        if n == 0:
            return []
        res = [0] * n
        res[:n] = nums  # may need to copy, nums[:]
        res[n:] = nums
        return res

# @lc code=end

