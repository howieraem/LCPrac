#
# @lc app=leetcode id=772 lang=python3
#
# [772] Basic Calculator III
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n)
    def calculate(self, s: str) -> int:
        i = 0
        n = len(s)

        # DFS with implicit stack(s)
        def helper(s):
            # Default to '+' because if the first number of an expression is positive 
            # then it doesn't have a plus sign
            pre_op = '+'
            num = 0
            nums = []

            nonlocal i
            while i < n:
                c = s[i]
                i += 1

                is_digit = c.isdigit()
                if is_digit:
                    num *= 10
                    num += int(c)
                elif c == '(':
                    num = helper(s)

                # Deal with operations when c is an operator or 
                # the index i has reached the end of s
                # if (not is_digit and c != ' ') or i == n:
                if not is_digit or i == n:
                    if pre_op == '+':
                        nums.append(num)
                    elif pre_op == '-':
                        nums.append(-num)
                    elif pre_op == '*':
                        nums[-1] *= num
                    elif pre_op == '/':
                        # nums[-1] //= num won't work for negative num 
                        nums[-1] = int(nums[-1] / num)
                    
                    num = 0
                    pre_op = c

                if c == ')':
                    break

            return sum(nums)

        return helper(s)
        
# @lc code=end

