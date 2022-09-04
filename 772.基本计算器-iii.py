#
# @lc app=leetcode id=772 lang=python3
#
# [772] Basic Calculator III
#
from collections import deque

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n)
    def calculate(self, s: str) -> int:
        return self.helper(deque(s))

    @staticmethod
    def helper(s: deque):
        # Note that s is passed by reference. Any recursive calls
        # will modify s.
        nums = []
        op = '+'
        cur = 0

        while len(s):
            c = s.popleft()
            if c == ' ':
                continue
            isdigit = c.isdigit()
            if isdigit:
                cur = cur * 10 + int(c)
            elif c == '(':
                cur = Solution.helper(s)

            # Character is one of {'+', '-', '*', '/'}
            if not isdigit or not s:
                if op == '+':
                    nums.append(cur)
                elif op == '-':
                    nums.append(-cur)
                elif op == '*':
                    nums[-1] *= cur
                elif op == '/':
                    nums[-1] = int(nums[-1] / cur)
                cur = 0
                op = c

            if c == ')':
                break

        return sum(nums)



        
# @lc code=end

