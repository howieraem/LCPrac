#
# @lc app=leetcode id=1150 lang=python3
#
# [1150] Check If a Number Is Majority Element in a Sorted Array
#
from typing import *

# @lc code=start
class Solution:
    # Binary search
    # T: O(k * log(n)), k := 2
    # S: O(1)
    def isMajorityElement(self, nums: List[int], target: int) -> bool:
        # K = 2
        n = len(nums)
        if n < 2:
            return False
        # window_sz = (n // K) + 1 
        window_sz = (n >> 1) + 1  # add 1 for strictly greater than n // 2

        def binary_search_last(target, l, r):
            while l < r:
                m = l + ((r - l) >> 1)
                if nums[m] > target:
                    r = m
                else:
                    l = m + 1
            return l - 1

        for i in range(0, n, window_sz):
            if nums[i] != target:
                continue
            r = binary_search_last(nums[i], i, n)
            l = r - window_sz + 1
            if l >= 0 and nums[l] == nums[i]:
                return True
            
        return False

# @lc code=end

