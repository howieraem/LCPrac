#
# @lc app=leetcode.cn id=282 lang=python3
#
# [282] 给表达式添加运算符
#
from typing import *

# @lc code=start
class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        n = len(num)
        res = []

        def backtrack(idx: int, pre_num: int, cur_num: int, val: int, path: list):
            if idx == n:
                if val == target and cur_num == 0:
                    res.append("".join(path[1:]))   # remove the leading "+"
                return
            
            cur_num = cur_num * 10 + int(num[idx])  # consider cur_num with multiple digits (i.e. >= 10)
            if cur_num > 0:
                # avoid cases like 1+05, 2*06, etc.
                backtrack(idx + 1, pre_num, cur_num, val, path)
            str_cur_num = str(cur_num)

            # add, incl. the first digit as val starts from 0
            path.append('+')
            path.append(str_cur_num)
            backtrack(idx + 1, cur_num, 0, val + cur_num, path)
            path.pop()
            path.pop()

            if len(path):   # can't do sub or mul without any pre_num
                # sub
                path.append('-')
                path.append(str_cur_num)
                backtrack(idx + 1, -cur_num, 0, val - cur_num, path)
                path.pop()
                path.pop()

                # mul
                # Since mul should be done prior to add and sub, undo operating with the previous number (+ve for add and -ve for sub),
                # then the new value becomes `val - pre_num + cur_num * pre_num`
                path.append('*')
                path.append(str_cur_num)
                backtrack(idx + 1, cur_num * pre_num, 0, val - pre_num + cur_num * pre_num, path)
                path.pop()
                path.pop()

        backtrack(0, 0, 0, 0, [])
        return res


# @lc code=end

