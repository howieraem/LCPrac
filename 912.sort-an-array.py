#
# @lc app=leetcode id=912 lang=python3
#
# [912] Sort an Array
#
from random import randint
from typing import *

# @lc code=start
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        # Heap sort
        # T: O(n * log(n))
        # S: O(1)
        # return self.heap_sort(nums)

        # Merge sort (out-of-place)
        # T: O(n * log(n))
        # S: O(n)
        # return self.merge_sort(nums, 0, len(nums) - 1)

        # Quick sort
        # T: O(n * log(n)) average, O(n ^ 2) worst
        # S: O(log(n)) 
        return self.quick_sort(nums, 0, len(nums) - 1)

    @staticmethod
    def quick_sort(nums, l, r):
        if l >= r:
            return nums
        p = Solution.partition(nums, l, r)
        Solution.quick_sort(nums, l, p - 1)
        Solution.quick_sort(nums, p + 1, r)
        return nums

    @staticmethod
    def partition(nums, l, r):
        p = randint(l, r)
        pivot = nums[p]
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
        
        nums[l], nums[j] = nums[j], nums[l]
        return j

    @staticmethod
    def merge_sort(nums, l, r):
        if l == r:
            return nums
        m = (l + r) >> 1
        Solution.merge_sort(nums, l, m)
        Solution.merge_sort(nums, m + 1, r)

        tmp = [0] * (r - l + 1)
        i = l
        j = m + 1
        k = 0

        while i <= m and j <= r:
            if nums[i] <= nums[j]:
                tmp[k] = nums[i]
                i += 1
            else:
                tmp[k] = nums[j]
                j += 1
            k += 1
        
        while i <= m:
            tmp[k] = nums[i]
            i += 1
            k += 1
        
        while j <= r:
            tmp[k] = nums[j]
            j += 1
            k += 1
        
        for p in range(k):
            nums[l + p] = tmp[p]
        
        return nums

    @staticmethod
    def heap_sort(nums):
        n = len(nums)
        for i in range((n >> 1) - 1, -1, -1):
            Solution.heapify(nums, i, n - 1)
        
        for i in range(n - 1, 0, -1):
            nums[0], nums[i] = nums[i], nums[0]  # simulate heap pop?
            Solution.heapify(nums, 0, i - 1)
        return nums

    @staticmethod
    def heapify(nums, l, r):
        root = l
        child = (root << 1) + 1

        while child <= r:
            if child <= r - 1 and nums[child] < nums[child + 1]:
                child += 1
            
            if nums[root] > nums[child]:
                return
            else:
                nums[root], nums[child] = nums[child], nums[root]
                root = child
                child = (root << 1) + 1

# @lc code=end

