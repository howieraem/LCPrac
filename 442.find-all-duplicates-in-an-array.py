#
# @lc app=leetcode id=442 lang=python3
#
# [442] Find All Duplicates in an Array
#
from typing import *

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def findDuplicates(self, nums: List[int]) -> List[int]:
        res = []

        # Constraints:
        # 1. all integers in range [1, n]
        # 2. each number appears once or twice
        # Instead of using auxiliary space, we can modify the original array to mark 
        # if a number has appeared before by negating the corresponding index based on 
        # constraint 1 
        for x in nums:
            idx = abs(x) - 1
            if nums[idx] < 0:  # appeared before
                res.append(idx + 1)
            else:
                nums[idx] *= -1
        
        return res

# @lc code=end

