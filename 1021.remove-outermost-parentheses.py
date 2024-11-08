#
# @lc app=leetcode id=1021 lang=python3
#
# [1021] Remove Outermost Parentheses
#

# @lc code=start
class Solution:
    # counters simulating stack
    # T: O(n)
    # S: O(1)
    def removeOuterParentheses(self, s: str) -> str:
        outer_cnt = 0
        inner_cnt = 0
        res = []
        for c in s:
            if c == '(':
                if outer_cnt == 0:
                    outer_cnt += 1
                else:
                    res.append(c)
                    inner_cnt += 1
            else:   # c == ')'
                if inner_cnt > 0:
                    res.append(c)
                    inner_cnt -= 1
                else:
                    outer_cnt -= 1

        return ''.join(res)
        
# @lc code=end

