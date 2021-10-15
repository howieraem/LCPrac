class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        if not m:
            return False
        n = len(matrix[0])
        if not n:
            return False
        i, j = m - 1, 0
        while i >= 0 and j < n:
            if matrix[i][j] > target:
                i -= 1
            elif matrix[i][j] < target:
                j += 1
            else:
                return True
        return False
