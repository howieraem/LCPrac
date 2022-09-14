#
# @lc app=leetcode id=1807 lang=python3
#
# [1807] Evaluate the Bracket Pairs of a String
#
from typing import *

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n)
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        d = dict(knowledge)
        res = []
        cur_key = []
        is_recording_key = False

        for c in s:
            if c == '(':
                is_recording_key = True
            elif c == ')':
                is_recording_key = False
                res.append(d.get("".join(cur_key), '?'))
                cur_key.clear()
            elif is_recording_key:
                cur_key.append(c)
            else:
                res.append(c)
        
        return "".join(res)
        
# @lc code=end

