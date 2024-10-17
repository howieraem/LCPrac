#
# @lc app=leetcode id=215 lang=python3
#
# [215] Kth Largest Element in an Array
#
import heapq
from random import randint
from typing import List

# @lc code=start
class Solution:
    # Quick select, iterative, works well if numbers are very distinct
    # T: O(n) average, O(n ^ 2) worst
    # S: O(1) (no recursion)
    def findKthLargest(self, nums: List[int], k: int) -> int:
        n = len(nums)
        k = n - k  # kth largest -> (n-k)th smallest

        l, r = 0, n - 1
        while l < r:
            m = self.partition(nums, l, r)
            if m == k:
                return nums[m]
            elif m > k:
                r = m - 1
            else:
                l = m + 1
        return nums[l]

    @staticmethod
    def partition(nums, l, r):
        p = randint(l, r)
        pivot = nums[p]

        # Swap the pivot to the beginning, so that the following 
        # swapping of other numbers is easier
        nums[l], nums[p] = nums[p], nums[l]

        i, j = l + 1, r

        while i <= j:
            if nums[i] <= pivot:
                i += 1
                continue
            if nums[j] >= pivot:
                j -= 1
                continue

            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1

        # Swap elements so that the pivot is now at the jth index.
        # At this point, numbers on the left of the pivot are less 
        # than or equal to the pivot, and numbers on the right of 
        # the pivot are greater than or equal to the pivot.
        nums[l], nums[j] = nums[j], nums[l]
        return j
    
    '''
    # Heap, works well if k is small and the numbers are not so distinct
    # T: O(n * log(k))
    # S: O(k)
    def findKthLargest(self, nums: List[int], k: int) -> int:
        min_heap = []
        for x in nums:
            heapq.heappush(min_heap, x)
            if len(min_heap) > k:
                # remove the bottom (n - k)
                heapq.heappop(min_heap)
        return min_heap[0]
    '''
# @lc code=end

