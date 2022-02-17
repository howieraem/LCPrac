#
# @lc app=leetcode id=1047 lang=python3
#
# [1047] Remove All Adjacent Duplicates In String
#

# @lc code=start
class Solution:
    def removeDuplicates(self, s: str) -> str:
        stack = []

        for c in s:
            if len(stack) and stack[-1] == c:
                stack.pop()
            else:
                stack.append(c)

        return "".join(stack)

# @lc code=end

