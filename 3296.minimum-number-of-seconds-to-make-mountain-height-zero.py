import heapq
from typing import List

class Solution:
    # T: O(mountainHeight * log(workerTimes))
    # S: O(workerTimes)
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: List[int]) -> int:
        min_heap = []

        for w in workerTimes:
            heapq.heappush(min_heap, (w, 0, w, w, 2))  # next_sum, cur_sum, cur_w_term, init_w, next_used

        while mountainHeight > 0:
            _, cur_sum, w_term, w0, used = heapq.heappop(min_heap)
            mountainHeight -= 1
            cur_sum += w_term
            next_w_term = w0 * used
            next_sum = cur_sum + next_w_term
            heapq.heappush(min_heap, (next_sum, cur_sum, next_w_term, w0, used + 1))

        return max(s for _, s, _, _, _ in min_heap)
