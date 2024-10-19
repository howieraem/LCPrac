from typing import List


class Solution:
    # T: O(n)
    # S: O(n)
    def taskSchedulerII(self, tasks: List[int], space: int) -> int:
        task_next_start_day = dict()
        cur_day = 0

        # Unlike Q621 where tasks can be permutated, the order of 
        # tasks here must be preserved
        for task in tasks:
            next_start_day = task_next_start_day.get(task, -1)
            if next_start_day > cur_day:
                cur_day = next_start_day
            cur_day += 1
            task_next_start_day[task] = cur_day + space

        return cur_day
