class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.small_half = []    # max heap
        self.large_half = []    # min heap
        self.n = 0

    def addNum(self, num: int) -> None:
        # negate num to simulate a max heap
        heapq.heappush(self.small_half, -num)
        small_heap_top = -heapq.heappop(self.small_half)
        heapq.heappush(self.large_half, small_heap_top)
        self.n += 1
        if self.n & 1:
            # if total length is odd, always make the max heap longer
            large_heap_top = heapq.heappop(self.large_half)
            heapq.heappush(self.small_half, -large_heap_top)

    def findMedian(self) -> float:
        if self.n & 1:
            return -self.small_half[0]
        return (-self.small_half[0] + self.large_half[0]) / 2.
