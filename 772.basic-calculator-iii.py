#
# @lc app=leetcode id=772 lang=python3
#
# [772] Basic Calculator III
#
from collections import deque

# @lc code=start
class Solution:
    def calculate(self, s: str) -> int:
        return self.helper(deque(s))

    @staticmethod
    def helper(s: deque):
        stack = []
        sign = '+'
        cur = 0

        while len(s):
            c = s.popleft()
            isdigit = c.isdigit()
            if isdigit:
                cur = cur * 10 + int(c)
            if c == '(':
                cur = Solution.helper(s)

            # Character is one of {'+', '-', '*', '/'}
            if (not isdigit and c != ' ') or not s:
                if sign == '+':
                    stack.append(cur)
                elif sign == '-':
                    stack.append(-cur)
                elif sign == '*':
                    stack[-1] *= cur
                elif sign == '/':
                    stack[-1] = int(stack[-1] / cur)
                cur = 0
                sign = c

            if c == ')':
                break
        
        return sum(stack)



        
# @lc code=end

