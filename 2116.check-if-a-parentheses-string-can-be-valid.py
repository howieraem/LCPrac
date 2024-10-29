#
# @lc app=leetcode id=2116 lang=python3
#
# [2116] Check if a Parentheses String Can Be Valid
#

# @lc code=start
class Solution:
    # Greedy
    # T: O(n)
    # S: O(1)
    def canBeValid(self, s: str, locked: str) -> bool:
        n = len(s)
        if n & 1:
            # length is odd, impossible to have equal numbers of '(' and ')'
            return False
        
        ## Check from left to right for matching '(' to ')'
        locked_char_balance = 0
        n_unlocked = 0   # no. of changeable chars
        for i in range(n):
            if locked[i] == '1':
                locked_char_balance += 1 if s[i] == '(' else -1
            else:
                n_unlocked += 1

            if n_unlocked + locked_char_balance < 0:
                # too many unbalanced ')'
                return False
        
        if locked_char_balance > n_unlocked:
            # too many unbalanced '('
            return False

        ## Check from right to left for matching ')' to '('
        locked_char_balance = 0
        n_unlocked = 0   # no. of changeable chars
        for i in range(n - 1, -1, -1):
            if locked[i] == '1':
                locked_char_balance += 1 if s[i] == ')' else -1
            else:
                n_unlocked += 1

            if n_unlocked + locked_char_balance < 0:
                # too many unbalanced '('
                return False
        
        if locked_char_balance > n_unlocked:
            # too many unbalanced ')'
            return False
        
        return True

# @lc code=end

