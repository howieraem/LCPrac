from collections import deque
from typing import List

class Solution:
    # T: O(n + max(arrival))
    # S: O(n)
    def timeTaken(self, arrival: List[int], state: List[int]) -> List[int]:
        # smallest index goes first, so use queues
        enter_q = deque()
        exit_q = deque()
        
        is_exit_mode = True
        t = 0
        n = len(arrival)
        res = [0] * n
        i = 0
        while i < n or len(enter_q) > 0 or len(exit_q) > 0:
            while i < n and arrival[i] <= t:
                if state[i] == 0:
                    enter_q.append(i)
                else:
                    exit_q.append(i)
                i += 1

            if is_exit_mode:
                if len(exit_q) > 0:
                    res[exit_q.popleft()] = t
                elif len(enter_q) > 0:
                    res[enter_q.popleft()] = t
                    is_exit_mode = False
            else:
                if len(enter_q) > 0:
                    res[enter_q.popleft()] = t
                elif len(exit_q) > 0:
                    res[exit_q.popleft()] = t
                    is_exit_mode = True
                else:
                    # door not used previously
                    is_exit_mode = True
            t += 1

        return res
