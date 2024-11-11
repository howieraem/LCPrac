#
# @lc app=leetcode id=1424 lang=python3
#
# [1424] Diagonal Traverse II
#
from collections import deque
from typing import *

# @lc code=start
class Solution:
    # BFS + matrix
    # space optimized compared to diagonal (r + c) bucket method
    # T: O(n)
    # S: O(sqrt(n))
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        # matrix can be jugged, so no. of columns n may not be a fixed number
        m = len(nums)
        if m == 0 or len(nums[0]) == 0:
            return []
        
        res = []

        q = deque()
        q.append((0, 0))

        while len(q) > 0:
            r, c = q.popleft()
            res.append(nums[r][c])

            # Unlike other grid BFS problems, 
            # we explore children for very 
            # specific cases, such as cells
            # of the first column.
            if c == 0 and r + 1 < m:
                # explore next row (down)
                q.append((r + 1, c))
            if c + 1 < len(nums[r]):
                # explore next column (right)
                q.append((r, c + 1))

        return res
        
    # Follow-up: matrix not jugged, no. of columns fixed
    # matrix traversal + geometry + advanced two pointers
    # T: O(m * n)
    # S: O(1)
    def findDiagonalOrderNotJugged(self, nums: List[List[int]]) -> List[int]:
        m = len(nums)
        if m == 0:
            return []
        n = len(nums[0])
        if n == 0:
            return []
        
        res = [0] * (m * n)
        p = 0

        row_start = 0
        col_start = 0
        i = 0
        j = 0
        while row_start < m and col_start < n:
            i = row_start
            j = col_start

            while 0 <= i < m and 0 <= j < n:
                res[p] = nums[i][j]
                p += 1

                # go up and right
                i -= 1
                j += 1

            if row_start == n - 1:
                # reached last row, increment start column
                col_start += 1
            else:
                # visit next row
                row_start += 1

        return res

            

# @lc code=end

