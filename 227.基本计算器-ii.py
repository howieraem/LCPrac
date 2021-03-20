#
# @lc app=leetcode.cn id=227 lang=python3
#
# [227] 基本计算器 II
#
from collections import deque

# @lc code=start
class Solution:
    def calculate(self, s: str) -> int:
        def helper(s: deque) -> int:
            stack = []
            sign = '+'
            num = 0

            while len(s):
                c = s.popleft()
                if c.isdigit():
                    # note: in other languages, `int(c)` might be written like
                    # `ord(c) - ord('0')` or literally `c - '0'`
                    num = 10 * num + int(c)
                # if c == '(':
                #     # recursively calculate expression/number within parethese
                #     num = helper(s)

                if (not c.isdigit() and c != ' ') or not len(s):
                    if sign == '+':
                        stack.append(num)
                    elif sign == '-':
                        stack.append(-num)
                    elif sign == '*':
                        stack[-1] *= num
                    elif sign == '/':
                        # note: `stack[-1] // num` does not work for negative numbers
                        stack[-1] = int(stack[-1] / num)
                    num = 0
                    sign = c
                
                # if c ==')':
                #     break   # stop any recursions
            return sum(stack)
        return helper(deque(s))

# @lc code=end

