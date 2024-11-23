#
# @lc app=leetcode id=150 lang=python3
#
# [150] Evaluate Reverse Polish Notation
#
from typing import List

# @lc code=start
class Solution:
    # stack + simulation
    # T: O(n)
    # S: O(n)
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for s in tokens:
            if s == '+':
                a = stack.pop()
                b = stack.pop()
                stack.append(b + a)
            elif s == '-':
                a = stack.pop()
                b = stack.pop()
                stack.append(b - a)
            elif s == '*':
                a = stack.pop()
                b = stack.pop()
                stack.append(b * a)
            elif s == '/':
                a = stack.pop()
                b = stack.pop()
                stack.append(int(b / a))
            else:
                # token is a number
                stack.append(int(s))
        
        return stack[-1]

# @lc code=end

