#
# @lc app=leetcode id=1354 lang=python3
#
# [1354] Construct Target Array With Multiple Sums
#
import heapq
from typing import *

# @lc code=start
class Solution:
    # Simulation + heap + math
    # T: O((n + log(max(target))) * log(n)), n := len(target)
    # S: O(n)
    def isPossible(self, target: List[int]) -> bool:
        n = len(target)
        if n == 0:
            return False
        if n == 1:
            # need to check here, otherwise we can encounter zero modulo error
            return target[0] == 1

        # Simulate the process backwards;
        # start with the max number and 
        # let it be the sum of the array
        # after the last operation; continue 
        # the process until we either reach 
        # 1 or encounter abnormalities
        cur_sum = sum(target)
        
        max_heap = []
        for a in target:
            heapq.heappush(max_heap, -a)

        while len(max_heap) > 0 and -max_heap[0] > 1:
            cur_max = -heapq.heappop(max_heap)  # process the max in every iteration
            rest_sum = cur_sum - cur_max
            
            # This will occur iff n = 2
            if rest_sum == 1:
                return True
            
            # Originally, the element to replace cur_max is `a = cur_max - rest_sum`.
            # When cur_max is significantly greater than the sum of other elements, 
            # there must be multiple similar rounds of operations. Do modulo to 
            # reduce the number of actual iterations.
            a = cur_max % rest_sum
            
            # impossible to reduce to all ones
            # 1. a becomes 0
            # 2. a didn't change
            if a == 0 or a == cur_max:
                return False

            heapq.heappush(max_heap, -a)

            cur_sum = rest_sum + a

        return True   # now heap top should equal 1

# @lc code=end

