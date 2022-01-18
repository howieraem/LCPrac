#
# @lc app=leetcode.cn id=65 lang=python3
#
# [65] 有效数字
#

# @lc code=start
class Solution:
    def isNumber(self, s: str) -> bool:
        num_seen = dot_seen = e_seen = False
        for i, c in enumerate(s.strip()):
            if c.isdigit():
                num_seen = True
            elif c == '.':
                if dot_seen or e_seen:
                    return False
                dot_seen = True
            elif c == 'E' or c == 'e':
                if e_seen or not num_seen:
                    return False
                e_seen = True
                num_seen = False
            elif c == '+' or c == '-':
                if i > 0 and s[i - 1] != 'e' and s[i - 1] != 'E':
                    return False
            else:
                return False
        return num_seen

# @lc code=end

