#
# @lc app=leetcode.cn id=8 lang=python3
#
# [8] 字符串转换整数 (atoi)
#
import re

# @lc code=start
class Solution:
    def myAtoi(self, s: str) -> int:
        """Most pythonic solution: use regex and `lstrip`."""
        # Java regex: "^\\s*([+-]?\\d+)"
        return max(min(int(*re.findall('^[\+\-]?\d+', s.lstrip())), 2**31 - 1), -2**31)

    """
    original solution:

    def myAtoi(self, str: str) -> int:
        # Note: in C/C++, probably need to use ASCII code.
        MAX_INT = 2**31     # not actually a constraint for python, but required by the question
        started = False
        digits = []
        for c in str:
            if not started:
                if c == ' ':    # can use str.lstrip() in python
                    continue
                elif c not in '+-' and not c.isdigit():
                    return 0
                started = True
                if c != '+':
                    digits.append(c)
            elif c.isdigit():
                digits.append(c)
            else:
                break
        
        # pythonic way
        digit_str = ''.join(digits)
        if not digit_str or digit_str == '-':
            return 0
        integer = int(digit_str)

        # non-pythonic way
        # if not digits or (len(digits) == 1 and (digits[0] == '-' or digits[1] == '+')):
        #     return 0
        # if digits[0] == '-':
        #     sign = -1
        #     digits = digits[1:]
        # else:
        #     sign = 1
        return max(min(num, MAX_INT-1), -MAX_INT)
    """

# @lc code=end
# s = Solution()
# print(s.myAtoi("-91283472332"))
