#
# @lc app=leetcode.cn id=304 lang=python3
#
# [304] 二维区域和检索 - 矩阵不可变
#

# @lc code=start
class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.prefix_sums = [[0]]
        rows = len(matrix)
        if rows > 0:
            cols = len(matrix[0])
            self.prefix_sums = [[0] * (cols + 1) for _ in range(rows + 1)]
            for i in range(rows):
                for j in range(cols):
                    self.prefix_sums[i+1][j+1] = self.prefix_sums[i+1][j] + self.prefix_sums[i][j+1] - self.prefix_sums[i][j] + matrix[i][j]

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return self.prefix_sums[row2+1][col2+1] - self.prefix_sums[row2+1][col1] - self.prefix_sums[row1][col2+1] + self.prefix_sums[row1][col1]


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
# @lc code=end

