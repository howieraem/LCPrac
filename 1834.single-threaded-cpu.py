#
# @lc app=leetcode id=1834 lang=python3
#
# [1834] Single-Threaded CPU
#
from heapq import *
from typing import *

# @lc code=start
class Solution:
    # T: O(n * log(n))
    # S: O(n)
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        # Sort by enqueue time and then processing time. CPU must deal with tasks
        # in the order of the enqueue time.
        tasks = sorted([(start, length, i) for i, (start, length) in enumerate(tasks)])
        
        heap = []
        cur_time = 0
        res = [0] * len(tasks)
        i = 0

        for start, length, task_id in tasks:
            # If the CPU is idle and there are available tasks, 
            # the CPU will choose the one with the shortest 
            # processing time. If multiple tasks have the 
            # same shortest processing time, it will choose 
            # the task with the smallest index. As heapq is
            # min heap, element in the heap should be a tuple 
            # (proc_time, index, ...).
            while len(heap) and cur_time < start:
                # Perform a task
                next_length, next_id, next_start = heappop(heap)
                res[i] = next_id
                i += 1
                cur_time = max(cur_time, next_start) + next_length
            heappush(heap, (length, task_id, start))

        while len(heap):
            # Perform the remaining tasks
            res[i] = heappop(heap)[1]
            i += 1
        return res

# @lc code=end

