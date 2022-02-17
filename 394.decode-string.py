#
# @lc app=leetcode id=394 lang=python3
#
# [394] Decode String
#
from collections import deque

# @lc code=start
class Solution:
    def decodeString(self, s: str) -> str:
        stack = deque()
        string = ""
        mult = 0

        for c in s:
            if c.isdigit():
                mult = mult * 10 + int(c)
            elif c == '[':
                stack.append((string, mult))
                string = ""
                mult = 0
            elif c == ']':
                left, m = stack.pop()
                for _ in range(m):
                    left += string
                string = left
            else:
                string += c
        return string

# @lc code=end

