import heapq
from typing import *


class Solution:
    # Heap + Math
    # T: O(n * log(k))
    # S: O(k)
    def putMarbles(self, weights: List[int], k: int) -> int:
        """
        Split weights into k groups at k split points,
        we have:
        score = (weights[0] + weights[s1]) + (weights[s1 + 1] + weights[s2]) + ... + (weights[s(k-1) + 1] + weights[-1])
              = weights[0] + weights[-1] + (weights[s1] + weights[s1 + 1]) + ... + (weights[s(k-1)] + weights[s(k-1) + 1])
        Now the problem is equivalent to finding the difference between 
        the top-(k-1) sum and the bottom-(k-1) sum of pairwise element sums in weights.
        """
        n = len(weights)
        top_heap = []  # min heap
        bottom_heap = []  # max heap
        k -= 1

        for i in range(n - 1):
            pair_sum = weights[i] + weights[i + 1]

            heapq.heappush(top_heap, pair_sum)
            heapq.heappush(bottom_heap, -pair_sum)

            if i >= k:
                heapq.heappop(top_heap)
                heapq.heappop(bottom_heap)

        # sum(top(k-1)) - sum(bottom(k-1))
        return sum(top_heap) + sum(bottom_heap)
    
    # note: if 2 * log(k) > log(n), then it is probably faster to 
    # sort all pairwise sums instead of using heaps
