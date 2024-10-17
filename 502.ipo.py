#
# @lc app=leetcode id=502 lang=python3
#
# [502] IPO
#
import heapq
from typing import List

# @lc code=start
class Solution:
    '''
    # Solution 1: Two heaps
    # T: O((n + k) * log(n))
    # S: O(n)
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        capital_heap = []  # min heap
        profit_heap = []   # max heap

        for p, c in zip(profits, capital):
            heapq.heappush(capital_heap, (c, p))

        for _ in range(k):
            while len(capital_heap) > 0 and capital_heap[0][0] <= w:
                _, p = heapq.heappop(capital_heap)
                heapq.heappush(profit_heap, -p)

            if len(profit_heap) == 0:
                break
        
            w -= heapq.heappop(profit_heap)  # max heap, negate to add to cur profit

        return w
    '''
    
    # Solution 2: Sort by init capital and use one heap 
    # T: O((n + k) * log(n))
    # S: O(n)
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        projs = []
        profit_heap = []   # max heap

        for p, c in zip(profits, capital):
            projs.append((c, p))
        projs.sort()  # sort by capital asc

        i = 0
        while k > 0:
            while i < len(projs) and projs[i][0] <= w:
                heapq.heappush(profit_heap, -projs[i][1])
                i += 1

            if len(profit_heap) == 0:
                break
        
            w -= heapq.heappop(profit_heap)  # max heap, negate to add to cur profit
            k -= 1

        return w

# @lc code=end

