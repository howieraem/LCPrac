#
# @lc app=leetcode id=496 lang=python3
#
# [496] Next Greater Element I
#
from typing import *

# @lc code=start
class Solution:
    # Mono-stack + hash map
    # T: O(n)
    # S: O(n)
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack = []
        map = dict()

        # Find next greater element for each element in nums2 
        n2 = len(nums2)
        for i in range(n2):
            # Numbers in stack are ordered DESC (strictly)
            while len(stack) and stack[-1] <= nums2[i]:
                map[stack.pop()] = nums2[i]
            stack.append(nums2[i])
        
        # No next greater element exists
        while len(stack) > 0:
            map[stack.pop()] = -1

        # Map the result to nums1
        # Every number in nums1 is also in nums2
        n1 = len(nums1)
        res = [0] * n1
        for i in range(n1):
            res[i] = map[nums1[i]]
        return res

# @lc code=end

