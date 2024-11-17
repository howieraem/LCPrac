from collections import deque
from typing import List


class Solution:
    # Hash map + greedy
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
    
    # Follow-up: task id type is limited to upper case English letters
    # Sliding window + bit mask
    # T: O(n)
    # S: O(space)
    def taskSchedulerIIWithUpperCaseTaskId(self, tasks: str, space: int) -> int:
        OFFSET = ord('A')
        n = len(tasks)

        cur_day = 0
        bitmask = 0         # Bitmask representing tasks in cooldown
        window = [0] * space
        window_pos = 0      # Current position in the sliding window

        i = 0 
        while i < n:
            current_task = tasks[i]
            task_bit = 1 << (ord(current_task) - OFFSET)

            if (bitmask & task_bit) == 0:
                # Task can be executed
                bitmask |= task_bit

                # Insert the task into the sliding window
                window[window_pos] = task_bit

                # Move window position
                window_pos = (window_pos + 1) % space
                
                # Move to the next task
                i += 1
            else:
                # Task is in cooldown, need to insert idle
                # Remove the task that is exiting the sliding window
                task_out = window[window_pos]
                if task_out != 0:
                    bitmask &= ~task_out
                
                # Insert idle (no task) into the window
                window[window_pos] = 0

                # Move window position
                window_pos = (window_pos + 1) % space

            cur_day += 1
        
        return cur_day


