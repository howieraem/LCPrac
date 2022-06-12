#
# @lc app=leetcode id=722 lang=python3
#
# [722] Remove Comments
#
from typing import *

# @lc code=start
class Solution:
    # T: O(n * l), n := the number of lines, l := max. line length
    # S: O(l)
    def removeComments(self, source: List[str]) -> List[str]:
        res = []
        buf = ""
        block_comment = False

        for line in source:
            i, l = 0, len(line)
            while i < l:
                if i < l - 1 and line[i:i + 2] == "//" and not block_comment:
                    break
                elif i < l - 1 and line[i:i + 2] == "/*" and not block_comment:
                    block_comment = True
                    i += 1
                elif i < l - 1 and line[i:i + 2] == "*/" and block_comment:
                    block_comment = False
                    i += 1
                elif not block_comment:
                    buf += line[i]
                i += 1

            if buf and not block_comment:
                res.append(buf)
                buf = ""
        return res
                


# @lc code=end

