import heapq
from typing import List

class Pt:
    def __init__(self, x, y):
        self.dist = abs(x) + abs(y)
    
    def __lt__(self, other):
        # make it a max heap
        return self.dist > other.dist

class Solution:
    # T: O(n * log(k))
    # S: O(k)
    def resultsArray(self, queries: List[List[int]], k: int) -> List[int]:
        pts = []

        res = [-1] * len(queries)

        for i, (x, y) in enumerate(queries):
            heapq.heappush(pts, Pt(x, y))  
            if i < k - 1:
                continue
            if len(pts) > k:
                heapq.heappop(pts)
            res[i] = pts[0].dist  # k-th smallest -> largest in heap
        return res
