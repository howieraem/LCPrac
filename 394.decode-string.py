#
# @lc app=leetcode id=394 lang=python3
#
# [394] Decode String
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n)
    def decodeString(self, s: str) -> str:
        stack = []
        cur_strs = []
        mult = 0

        for c in s:
            if c.isdigit():
                mult = mult * 10 + int(c)
            elif c == '[':
                stack.append((cur_strs, mult))
                cur_strs = []
                mult = 0
            elif c == ']':
                outer_strs, m = stack.pop()
                for _ in range(m):
                    outer_strs.extend(cur_strs)
                cur_strs = outer_strs
            else:
                cur_strs.append(c)
        return "".join(cur_strs)

# @lc code=end

