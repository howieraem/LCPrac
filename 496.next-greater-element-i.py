#
# @lc app=leetcode id=496 lang=python3
#
# [496] Next Greater Element I
#
from collections import deque
from typing import *

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n)
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack = deque()
        map = dict()

        n1, n2 = len(nums1), len(nums2)
        for i in range(n2):
            while len(stack) and nums2[i] > stack[-1]:
                map[stack.pop()] = nums2[i]
            stack.append(nums2[i])
        
        # No next greater element exists
        while len(stack):
            map[stack.pop()] = -1

        res = [0] * n1
        for i in range(n1):
            res[i] = map[nums1[i]]
        return res

# @lc code=end

