import heapq
from typing import List

class Solution:
    # Heap
    # T: O(m * n * log(min(n, k)))
    # S: O(m * min(n, k))
    def maxSum(self, grid: List[List[int]], limits: List[int], k: int) -> int:
        # For each row, we need the top elements, but they don't need to be strictly sorted
        def n_largest(k: int, arr: List[int]):
            if k <= 0:
                return []
            if k >= len(arr):
                return arr
            min_heap = []
            for i in range(k):
                heapq.heappush(min_heap, arr[i])
            for i in range(k, len(arr)):
                if arr[i] > min_heap[0]:
                    heapq.heapreplace(min_heap, arr[i])
                    # heapq.heappop()
                    # heapq.heappush(arr[i])
            return min_heap

        largest_candidates = []
        for row, limit in zip(grid, limits):
            largest_candidates.extend(n_largest(min(k, limit), row))

        return sum(n_largest(k, largest_candidates))
