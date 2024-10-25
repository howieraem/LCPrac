#
# @lc app=leetcode id=456 lang=python3
#
# [456] 132 Pattern
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n)
    def find132pattern(self, nums: List[int]) -> bool:
        stack = []
        mid = float('-inf')  # nums[k]

        for x in reversed(nums):  # IMPORTANT
            if x < mid:  # found nums[i]
                return True
            
            # mono-stack: numbers in stack are ordered DESC
            while len(stack) > 0 and stack[-1] < x:
                # update mid if a larger number is found to be nums[j]
                mid = stack.pop()

            stack.append(x)
        
        return False


# @lc code=end

