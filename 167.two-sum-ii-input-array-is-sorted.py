#
# @lc app=leetcode id=167 lang=python3
#
# [167] Two Sum II - Input Array Is Sorted
#
from typing import *

# @lc code=start
class Solution:
    # Two pointers
    # T: O(n)
    # S: O(1)
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i = 0
        j = len(numbers) - 1
        
        # numbers sorted, move one pointer in each iteration 
        # depending on the current sum compared with target
        while i < j:
            x = numbers[i] + numbers[j]
            if x == target:
                return [i + 1, j + 1]  # answer should be 1-indexed
            elif x > target:
                j -= 1
            else:
                i += 1
        return [-1, -1]

# @lc code=end

