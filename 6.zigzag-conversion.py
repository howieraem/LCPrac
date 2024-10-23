#
# @lc app=leetcode id=6 lang=python3
#
# [6] Zigzag Conversion
#

# @lc code=start
class Solution:
    # T: O(len(s))
    # S: O(len(s) * numRows)
    def convert(self, s: str, numRows: int) -> str:
        if numRows < 2:
            return s
        res = [[] for _ in range(numRows)]
        row_idx = 0
        row_dirn = -1
        LAST = numRows - 1
        for c in s:
            res[row_idx].append(c)
            if row_idx == 0 or row_idx == LAST:
                # flip sign to reverse the direction
                row_dirn = (~row_dirn + 1)  # either +1 or -1
            row_idx += row_dirn
        return "".join("".join(row) for row in res)

# @lc code=end

