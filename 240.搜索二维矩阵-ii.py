#
# @lc app=leetcode.cn id=240 lang=python3
#
# [240] 搜索二维矩阵 II
#

# @lc code=start
class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m = len(matrix)
        if not m:
            return False
        n = len(matrix[0])
        row = m-1
        col = 0

        while col < n and row >= 0:
            # Based on properties of row and column numbers in the matrix,
            # shift pointers. Time complexity O(m+n).
            if matrix[row][col] > target:
                row -= 1
            elif matrix[row][col] < target:
                col += 1
            else:
                return True
        return False
        
# @lc code=end

