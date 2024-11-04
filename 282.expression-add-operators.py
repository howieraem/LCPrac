#
# @lc app=leetcode id=282 lang=python3
#
# [282] Expression Add Operators
#
from typing import *

# @lc code=start
class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        res = []
        n = len(num)

        def dfs(path: str, idx: int, val: int, pre_mult_factor: int) -> None:
            if idx == n:
                if val == target:
                    res.append(path)
                return
            
            for i in range(idx, n):
                if i != idx and num[idx] == '0':
                    break

                cur_str = num[idx:i + 1]
                cur = int(cur_str)

                if idx > 0:
                    # Try all three operations
                    dfs(path + "+" + cur_str, i + 1, 
                        val + cur, cur)
                    dfs(path + "-" + cur_str, i + 1, 
                        val - cur, -cur)

                    # Some explanation for `val - mult + mult * cur`:
                    # Suppose num is "1234". Now path is "1+2+3". If we wanna insert a '*' 
                    # between 3 and 4, path will become "1+2+3*4" which should be evaluated 
                    # to 1+2+3-3+3*4. The addition of "3" previously must be undone.  
                    dfs(path + "*" + cur_str, i + 1, 
                        val - pre_mult_factor + pre_mult_factor * cur, pre_mult_factor * cur)
                else:
                    # First digit, 0 + digit
                    dfs(path + cur_str, i + 1, 
                        cur, cur)

        dfs("", 0, 0, 0)
        return res

# @lc code=end

