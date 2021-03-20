#
# @lc app=leetcode.cn id=6 lang=python3
#
# [6] Z 字形变换
#

# @lc code=start
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows < 2:
            return s
        res = ["" for _ in range(numRows)]
        i, dirn_flag = 0, -1
        for c in s:
            res[i] += c
            if i == 0 or i == numRows - 1:
                dirn_flag = -dirn_flag    # reverse the direction
            i += dirn_flag
        return "".join(res)

# @lc code=end
