#
# @lc app=leetcode id=295 lang=python3
#
# [295] Find Median from Data Stream
#
import heapq

# @lc code=start
class MedianFinder:
    def __init__(self):
        # max heap that stores the smaller half of the data
        self.small_heap = []
        
        # min heap that stores the larger half of the data
        self.large_heap = []

        self.sz = 0

    # O(log(n))
    def addNum(self, num: int) -> None:
        heapq.heappush(self.large_heap, num)
        large_heap_top = heapq.heappop(self.large_heap)
        heapq.heappush(self.small_heap, -large_heap_top)
        self.sz += 1

        if self.sz & 1:
            # Make the large heap store one more element
            # if data size is odd
            small_heap_top = -heapq.heappop(self.small_heap)
            heapq.heappush(self.large_heap, small_heap_top)

    # O(1)
    def findMedian(self) -> float:
        if self.sz & 1:
            return self.large_heap[0]
        return (-self.small_heap[0] + self.large_heap[0]) / 2.0 


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
# @lc code=end

