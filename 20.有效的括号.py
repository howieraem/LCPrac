#
# @lc app=leetcode.cn id=20 lang=python3
#
# [20] 有效的括号
#

# @lc code=start
class Solution:
    RULES = {
        ')': '(',
        ']': '[',
        '}': '{',
    }

    LEFT = {'(', '[', '{'}

    def isValid(self, s: str) -> bool:
        left_brackets = []
        for ch in s:
            if ch in self.LEFT:
                left_brackets.append(ch)
            else:
                if left_brackets and self.RULES[ch] == left_brackets[-1]:
                    left_brackets.pop()
                else:
                    return False
        return not left_brackets

# @lc code=end

