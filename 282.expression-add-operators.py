#
# @lc app=leetcode id=282 lang=python3
#
# [282] Expression Add Operators
#
from typing import *

# @lc code=start
class Solution:
    # Backtracking
    # T: O(n * 4 ^ n)
    # S: O(n)
    def addOperators(self, num: str, target: int) -> List[str]:
        res = []
        n = len(num)

        def helper(path: List[str], idx: int, path_val: int, pre_mult_factor: int) -> None:
            if idx == n:
                if path_val == target:
                    res.append(''.join(path))
                return
            
            for i in range(idx, n):
                if i > idx and num[idx] == '0':
                    # number with leading zeros: we can't have numbers with multiple digits started with zero
                    break

                cur_str_num = num[idx:i + 1]
                cur_num = int(cur_str_num)

                if idx > 0:
                    # Try all three operations
                    # plus
                    path.append('+')
                    path.append(cur_str_num)
                    helper(path, i + 1, path_val + cur_num, cur_num)
                    path.pop()
                    path.pop()
                    
                    # minus
                    path.append('-')
                    path.append(cur_str_num)
                    helper(path, i + 1, path_val - cur_num, -cur_num)
                    path.pop()
                    path.pop()

                    # multiply
                    # Explanations for `path_val - mult + mult * cur_num`:
                    # Suppose num is "1234". Now path is "1+2+3". If we wanna insert a '*' 
                    # between 3 and 4, path will become "1+2+3*4" which should be evaluated 
                    # to 1+2+3-3+3*4. The addition of "3" previously must be undone.  
                    path.append('*')
                    path.append(cur_str_num)
                    helper(path, i + 1, path_val - pre_mult_factor + pre_mult_factor * cur_num, pre_mult_factor * cur_num)
                    path.pop()
                    path.pop()
                else:
                    # First digit, 0 + digit
                    path.append(cur_str_num)
                    helper(path, i + 1, cur_num, cur_num)
                    path.pop()

        path = []
        helper(path, 0, 0, 0)
        return res

# @lc code=end

