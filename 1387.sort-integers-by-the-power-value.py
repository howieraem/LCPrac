#
# @lc app=leetcode id=1387 lang=python3
#
# [1387] Sort Integers by The Power Value
#
import heapq

# @lc code=start
class Solution:
    # Memoized recursion + heap / sorting
    # T: O(n * log(k)), n := hi - lo
    # S: O(n) recursion
    def getKth(self, lo: int, hi: int, k: int) -> int:
        memo = dict()
        memo[1] = 0

        def calc_steps(x: int) -> int:
            if x not in memo:
                memo[x] = 1 + calc_steps(x * 3 + 1 if x & 1 else x >> 1)
            return memo[x]

        pq = []
        for x in range(lo, hi + 1):
            # To keep the heap complexity low, use a max heap and 
            # pop the larger values on the way, so that the heap 
            # top ends up with the k-th element
            heapq.heappush(pq, (-calc_steps(x), -x))
            if len(pq) > k:
                heapq.heappop(pq)
        return -pq[0][1]
        
# @lc code=end

