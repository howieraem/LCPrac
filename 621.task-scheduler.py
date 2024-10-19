#
# @lc app=leetcode id=621 lang=python3
#
# [621] Task Scheduler
#
from typing import List

# @lc code=start
class Solution:
    # T: O(len(tasks))
    # S: O(n_task_types)
    def leastInterval(self, tasks: List[str], n: int) -> int:
        freqs = [0] * 26
        OFFSET = ord('A')
        n_tasks = len(tasks)
        max_freq = 0
        n_tasks_with_max_freq = 0

        for t in tasks:
            ci = ord(t) - OFFSET
            freqs[ci] += 1
            if freqs[ci] > max_freq:
                max_freq = freqs[ci]
                n_tasks_with_max_freq = 1
            elif freqs[ci] == max_freq:
                n_tasks_with_max_freq += 1

        n_slots_for_less_freq_tasks = (max_freq - 1) * (n - (n_tasks_with_max_freq - 1))
        n_tasks_with_less_freqs = n_tasks - max_freq * n_tasks_with_max_freq
        n_slots_idle = max(0, n_slots_for_less_freq_tasks - n_tasks_with_less_freqs)
        
        return n_tasks + n_slots_idle

# @lc code=end

