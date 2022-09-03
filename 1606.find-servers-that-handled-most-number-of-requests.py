#
# @lc app=leetcode id=1606 lang=python3
#
# [1606] Find Servers That Handled Most Number of Requests
#
import heapq
from typing import List

# @lc code=start
class Solution:
    # T: O(n * log(k)), n := the number of requests
    # S: O(k)
    def busiestServers(self, k: int, arrival: List[int], load: List[int]) -> List[int]:
        avail = list(range(k))
        busy = []
        n_handled = [0] * k

        for i, (arr_t, process_t) in enumerate(zip(arrival, load)):
            while len(busy) and busy[0][0] <= arr_t:  # check if any servers finish processing prev. reqs
                _, j = heapq.heappop(busy)
                # remap j so that it's within interval [i, i + k - 1], 
                # and push it to avail server id heap
                heapq.heappush(avail, i + (j - i) % k)

            if len(avail):
                j = heapq.heappop(avail) % k
                # arr_t + process_t will be the end time of the req being handled
                heapq.heappush(busy, (arr_t + process_t, j))
                n_handled[j] += 1

            # drop req if no avail server
        
        max_handled = max(n_handled)
        return [i for i in range(k) if n_handled[i] == max_handled]

# @lc code=end

