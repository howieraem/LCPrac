#
# @lc app=leetcode.cn id=74 lang=python3
#
# [74] 搜索二维矩阵
#
from typing import List

# @lc code=start
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        """Solution: one binary search with index conversion from flattened to 2D, O(log(MN))"""
        m = len(matrix)
        if not m:
            return False
        n = len(matrix[0])
        
        # 二分查找
        left, right = 0, m * n - 1
        while left <= right:
            # Since the last element of a row is greater than the first element of its next row,
            # one can "flatten" the matrix to a 1D array and do binary search on it.
            pivot_idx = (left + right) >> 1
            i, j = divmod(pivot_idx, n)     # convert pivot to x, y indices
            pivot_element = matrix[i][j]
            if target == pivot_element:
                return True
            elif target < pivot_element:
                right = pivot_idx - 1
            else:
                left = pivot_idx + 1
        return False

    """
    original solution, O(Nlog(M)):

    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for row in matrix:
            if not row or target > row[-1]:
                continue
            if target < row[0]:
                break
            start, end = 0, len(row)
            while start < end:
                mid = (start + end) >> 1
                num = row[mid]
                if num > target:
                    end = mid
                elif num < target:
                    start = mid+1
                else:
                    return True
        return False
    """


# @lc code=end
m = [[1,3,5,7,8], [10,11,16,20,21], [23,30,34,50,51]]
s = Solution()
print(s.searchMatrix(m, 13))
