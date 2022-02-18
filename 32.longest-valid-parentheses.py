#
# @lc app=leetcode id=32 lang=python3
#
# [32] Longest Valid Parentheses
#

# @lc code=start
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        # Consider the case "()", index of ')' is 1, length = 1 - (-1) = 2
        stack = [-1]

        res = 0

        for i, c in enumerate(s):
            # We only update the result (max) when we find a "pair".
            # If we find a pair, we throw this pair away and see 
            # how big the gap is between current and previous invalid.
            if c == ')' and len(stack) > 1 and s[stack[-1]] == '(':
                stack.pop()
                res = max(res, i - stack[-1])
            else:
                stack.append(i)

        return res
        
# @lc code=end

