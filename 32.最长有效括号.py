#
# @lc app=leetcode.cn id=32 lang=python3
#
# [32] 最长有效括号
#

# @lc code=start
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        """Need to iterate twice, but space is O(1)."""
        n, left, right, curr_max = len(s), 0, 0, 0
        for i in range(n):
            if s[i] =='(':
                left += 1
            else:
                right += 1
            if left == right:
                curr_max = max(curr_max, 2*right)
            elif right > left:
                left = right = 0
        left = right = 0
        for i in range(n-1, -1, -1):
            if s[i] =='(':
                left += 1
            else:
                right += 1
            if left == right:
                curr_max = max(curr_max, 2*left)
            elif right < left:
                left = right = 0
        return curr_max

    def longestValidParentheses(self, s: str) -> int:
        """Stack approach, O(N) space."""
        curr_max = 0
        stack = [-1]
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)     # push
            else:
                stack.pop()
                if not stack:
                    # 如果栈为空，说明当前的右括号为没有被匹配的右括号，我们将其下标放入栈中来更新「最后一个没有被匹配的右括号的下标」
                    stack.append(i)
                else:
                    # 如果栈不为空，当前右括号的下标减去栈顶元素即为「以该右括号为结尾的最长有效括号的长度」
                    curr_max = max(curr_max, i-stack[-1])   # i-stack.peep()
        return curr_max

# @lc code=end

