#
# @lc app=leetcode id=480 lang=python3
#
# [480] Sliding Window Median
#
import heapq
from typing import *

# @lc code=start
'''
class MedianFinder:
    def __init__(self):
        self.small = []
        self.large = []
        self.sz = 0

    # O(log(n))
    def insert(self, num: int) -> None:
        heapq.heappush(self.large, num)
        self.move(self.large, self.small)
        self.sz += 1

        if self.sz & 1:
            # Make the large heap store one more element
            # if data size is odd
            self.move(self.small, self.large)

    # O(1)
    def median(self) -> float:
        if self.sz & 1:
            return self.large[0]
        return (-self.small[0] + self.large[0]) / 2.0 

    # O(n)
    def remove(self, num):
        self.sz -= 1
        if num >= self.large[0]:
            self.heap_remove(self.large, num)
        else:
            self.heap_remove(self.small, -num)
        self.balance()

    def balance(self):
        while len(self.small) > len(self.large):
            self.move(self.small, self.large)
        while len(self.large) - len(self.small) > 1:
            self.move(self.large, self.small)

    @staticmethod
    def heap_remove(heap: list, n):
        i = heap.index(n)   # O(n)
        heap[i] = heap[-1]
        heap.pop()

        # Approach 1, O(n)
        # heapq.heapify(heap)

        # Approach 2, O(log(n))
        if i < len(heap):
            heapq._siftup(heap, i)
            heapq._siftdown(heap, 0, i)

    @staticmethod
    def move(src: list, dst: list):
        top = heapq.heappop(src)
        heapq.heappush(dst, -top)
'''

class Solution:
    '''
    # Solution 1: Directly modified from Q295 median finder
    # T: O(n * k)
    # S: O(k)
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        n = len(nums)
        res = [0] * (n - k + 1)

        mf = MedianFinder()
        for i in range(k):
            mf.insert(nums[i])
        res[0] = mf.median()

        for i in range(k, n):
            j = i - k
            mf.insert(nums[i])
            mf.remove(nums[j])
            res[j + 1] = mf.median()
        return res
    '''

    # Solution 2: sliding window + advanced removal from heap
    # T: O(n * log(k))
    # S: O(k)
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        n = len(nums)
        res = [0] * (n - k + 1)
        small = []   # max heap, heap top is the maximum
        large = []   # min heap, heap top is the minimum

        # Initial window
        for r in range(k):
            # Make the large heap contain no less elements than the small heap,
            # so that when there are an odd number of elements in total, the 
            # large heap's top is the median 
            if len(small) == len(large):
                tup = heapq.heappushpop(small, (-nums[r], r))  # heappushpop is faster than heappush + heappop in sequence
                heapq.heappush(large, (-tup[0], tup[1]))
            else:
                tup = heapq.heappushpop(large, (nums[r], r))
                heapq.heappush(small, (-tup[0], tup[1]))

        res[0] = self.median(small, large, k)

        for r in range(k, n):
            # Advanced efficient steps to shift the left boundary of the window:
            # 1. Move the element at the left boundary from one heap to another if needed
            # 2. Do heap pop based on the left boundary index of the window
            l = r - k
            if nums[r] >= large[0][0]:
                heapq.heappush(large, (nums[r], r))
                if nums[l] <= large[0][0]:
                    # the large heap will not be balanced after window slides
                    self.move(large, small)
            else:
                heapq.heappush(small, (-nums[r], r))
                if nums[l] >= large[0][0]:
                    # the small heap will not be balanced after window slides
                    self.move(small, large)
            while len(large) > 0 and large[0][1] <= l:
                heapq.heappop(large)
            while len(small) > 0 and small[0][1] <= l:
                heapq.heappop(small)

            res[l + 1] = self.median(small, large, k)

        return res

    @staticmethod
    # T: O(log(k))
    def move(src, dst):
        x, i = heapq.heappop(src)
        heapq.heappush(dst, (-x, i))

    @staticmethod
    # T: O(1)
    def median(small, large, k):
        if k & 1:
            return large[0][0]
        return (-small[0][0] + large[0][0]) / 2.

# @lc code=end

