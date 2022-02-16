#
# @lc app=leetcode id=215 lang=python3
#
# [215] Kth Largest Element in an Array
#
from random import randint
from typing import List

# @lc code=start
class Solution:
    # T: O(n) average, O(n ^ 2) worst
    # S: O(1) (no recursion)
    def findKthLargest(self, nums: List[int], k: int) -> int:
        n = len(nums)
        k = n - k  # kth largest -> (n-k)th smallest

        l, r = 0, n - 1
        while l < r:
            m = self.parition(nums, l, r)
            if m == k:
                return nums[m]
            elif m > k:
                r = m - 1
            else:
                l = m + 1
        return nums[l]

    @staticmethod
    def parition(nums, l, r):
        p = randint(l, r)
        pivot = nums[p]

        # Move the pivot to the begining, so that the following 
        # swapping of other numbers is easier
        nums[l], nums[p] = nums[p], nums[l]

        i, j = l + 1, r

        while True:
            while i < r and nums[i] <= pivot:
                i += 1
            while j > l and nums[j] >= pivot:
                j -= 1
            
            if i >= j:
                break

            nums[i], nums[j] = nums[j], nums[i]

        # Swap elements so that the pivot is now at the jth index.
        # At this point, numbers on the left of the pivot are less 
        # than or equal to the pivot, and numbers on the right of 
        # the pivot are greater than or equal to the pivot.
        nums[l], nums[j] = nums[j], nums[l]
        return j


# @lc code=end

