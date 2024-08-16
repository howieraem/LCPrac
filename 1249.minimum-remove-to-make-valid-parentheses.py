#
# @lc app=leetcode id=1249 lang=python3
#
# [1249] Minimum Remove to Make Valid Parentheses
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n)
    def minRemoveToMakeValid(self, s: str) -> str:
        N = len(s)
        keep_mask = [True] * N

        stack = []
        for i, c in enumerate(s):
            if c == '(':
                # not yet matched to a ')'
                stack.append(i)
                keep_mask[i] = False
            elif c == ')':
                if len(stack) == 0:
                    # can't be matched to a previous '('
                    keep_mask[i] = False
                else:
                    last_left_idx = stack.pop()
                    keep_mask[last_left_idx] = True

        return ''.join(c for i, c in enumerate(s) if keep_mask[i])

        
# @lc code=end

