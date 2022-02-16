#
# @lc app=leetcode id=224 lang=python3
#
# [224] Basic Calculator
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n_brackets)
    def calculate(self, s: str) -> int:
        i = 0
        n = len(s)

        def helper(s):
            pre_op = '+'
            num = 0
            nums = []

            nonlocal i
            while i < n:
                c = s[i]
                i += 1

                is_digit = c.isdigit()
                if is_digit:
                    num = num * 10 + int(c)
                elif c == '(':
                    num = helper(s)

                # Deal with operations when c is an operator or 
                # the index i has reached the end of s
                if (not is_digit and c != ' ') or i == n:
                    if pre_op == '+':
                        nums.append(num)
                    elif pre_op == '-':
                        nums.append(-num)
                    
                    num = 0
                    pre_op = c

                if c == ')':
                    break

            return sum(nums)

        return helper(s)


# @lc code=end

