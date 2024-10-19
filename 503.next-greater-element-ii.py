#
# @lc app=leetcode id=503 lang=python3
#
# [503] Next Greater Element II
#
from typing import List

# @lc code=start
class Solution:
    # Mono stack
    # T: O(n)
    # S: O(n)
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [-1] * n
        stack = []

        # Idea: Make the array "circular" by virtually making a copy to its right,
        # i.e. iterate from 0 to 2n and then use modulus to get the original index
        for i in range(n << 1):
            # stack of indices (corresponding numbers are ordered DESC)
            while len(stack) > 0 and nums[stack[-1]] < nums[i % n]:
                res[stack.pop()] = nums[i % n]
            stack.append(i % n)

        return res


# @lc code=end

