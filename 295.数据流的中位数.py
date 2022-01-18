#
# @lc app=leetcode.cn id=295 lang=python3
#
# [295] 数据流的中位数
#
import heapq

# @lc code=start
class MedianFinder:
    """
    如果数据流中每读出1个数后都排一次序，「中位数」就位于这些数的「中间」。「中位数」把它们分为两个部分，
    一部分是「前有序数组」，另一部分是「后有序数组」。我们发现如下事实：
        - 当从数据流中读出的数的个数为奇数的时候，中位数是「前有序数组」中的最大值
        - 当从数据流中读出的数的个数为偶数的时候，左中位数是「前有序数组」中的最大值，
          右中位数是「后有序数组」中的最小值，最终中位数即左中位数与右中位数的平均

    堆这一数据结构可以O(1)获取排序数组的最值，且插入为O(logN)，优于不少排序算法的O(NlogN)。
    """
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.heap_small = []  # 大根堆存储「前有序数组」
        self.heap_large = []  # 小根堆存储「后有序数组」
        self.len = 0

    def addNum(self, num: int) -> None:
        heapq.heappush(self.heap_small, -num)  # since python's heapq is min heap, need to negate the number to simulate max heap
        heap_small_top = heapq.heappop(self.heap_small)
        heapq.heappush(self.heap_large, -heap_small_top)
        self.len += 1
        if self.len & 1:    # if total size is odd, make the size of max heap larger 
            heap_large_top = heapq.heappop(self.heap_large)
            heapq.heappush(self.heap_small, -heap_large_top)

    def findMedian(self) -> float:
        if self.len & 1:
            return -self.heap_small[0]
        return (-self.heap_small[0] + self.heap_large[0]) / 2.


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
# @lc code=end

