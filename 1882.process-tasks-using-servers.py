#
# @lc app=leetcode id=1882 lang=python3
#
# [1882] Process Tasks Using Servers
#
import heapq
from typing import List

# @lc code=start
class Solution:
    # T: O(T * log(S)), T := len(tasks), S := len(servers)
    # S: O(T + S)
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        avail_server_min_heap = [(w, i) for i, w in enumerate(servers)]
        heapq.heapify(avail_server_min_heap)  # This is faster than using heappush in a for loop

        busy_server_min_heap = []
        res = [-1] * len(tasks)
        res_i = 0
        for j, task_t in enumerate(tasks):
            while len(busy_server_min_heap) and busy_server_min_heap[0][0] <= j:
                _, w, i = heapq.heappop(busy_server_min_heap)
                heapq.heappush(avail_server_min_heap, (w, i))

            if len(avail_server_min_heap):
                # Avail server task assignment rule: smallest weight, then smallest index
                w, i = heapq.heappop(avail_server_min_heap)
            else:
                # If there are no free servers and the queue is not empty, we wait until a server 
                # becomes free and immediately assign the next task. If multiple servers become 
                # free at the same time, then multiple tasks from the queue will be assigned in 
                # order of insertion following the weight and index priorities above.
                j, w, i = heapq.heappop(busy_server_min_heap)

            res[res_i] = i
            res_i += 1

            # Add j to t to reserve insertion order?
            heapq.heappush(busy_server_min_heap, (j + task_t, w, i))

        return res

# @lc code=end

