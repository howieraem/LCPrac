#
# @lc app=leetcode id=636 lang=python3
#
# [636] Exclusive Time of Functions
#
from typing import *

# @lc code=start
class Solution:
    # T: O(len(logs))
    # S: O(len(logs))
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        pre_t = 0
        stack = []  # stores function ids
        res = [0] * n
        for log in logs:
            fid, action, t = log.split(":")
            fid, t = int(fid), int(t)
            if action == "start":
                if len(stack):
                    # Record the exclude time of previous function which 
                    # may still be executed later
                    res[stack[-1]] += t - pre_t
                stack.append(fid)
            else:
                t += 1  # IMPORTANT: end timestamp includes that second (up to the end of the second)
                res[stack.pop()] += t - pre_t
            pre_t = t
        return res


# @lc code=end

