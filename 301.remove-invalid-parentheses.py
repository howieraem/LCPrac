#
# @lc app=leetcode id=301 lang=python3
#
# [301] Remove Invalid Parentheses
#
from collections import deque
from typing import *

# @lc code=start
class Solution:
    # T: O(n * 2 ^ n), n := len(s)
    # S: O(n ^ 2)
    def removeInvalidParentheses(self, s: str) -> List[str]:
        res = []
        vis = set()
        q = deque()

        q.append(s)
        vis.add(s)

        # Once a valid result appears, we don't care about 
        # its "children" valid results that are shorter
        not_found = True

        while len(q) and not_found:
            l = len(q)

            for _ in range(l):
                s = q.popleft()
                if self.valid(s):
                    res.append(s)
                    not_found = False

                if not_found:
                    for i in range(len(s)):
                        if s[i] != '(' and s[i] != ')':
                            continue

                        t = s[:i] + s[i + 1:]
                        if t not in vis:
                            vis.add(t)
                            q.append(t)
        
        return res

    @staticmethod  
    def valid(s):
        cnt = 0
        for c in s:
            if c == '(':
                cnt += 1
            elif c == ')':
                cnt -= 1
                if cnt < 0:
                    return False
        return cnt == 0


# @lc code=end

