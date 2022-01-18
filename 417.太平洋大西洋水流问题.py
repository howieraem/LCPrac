#
# @lc app=leetcode.cn id=417 lang=python3
#
# [417] 太平洋大西洋水流问题
#

# @lc code=start
class Solution:
    DIRNS = (-1, 0, 1, 0, -1)   # (-1, 0), (0, 1), (1, 0), (0, -1)

    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        res = []
        if not matrix or not matrix[0]:
            return res
        m, n = len(matrix), len(matrix[0])
        can_reach_p = [[False] * n for _ in range(m)]
        can_reach_a = [[False] * n for _ in range(m)]

        # start search from the 4 boundaries and find paths with ascending altitude
        for i in range(m):
            self.__dfs(matrix, can_reach_p, i, 0)       # top
            self.__dfs(matrix, can_reach_a, i, n - 1)   # bottom
        for i in range(n):
            self.__dfs(matrix, can_reach_p, 0, i)       # left
            self.__dfs(matrix, can_reach_a, m - 1, i)   # right
        
        # record results
        for i in range(m):
            for j in range(n):
                if can_reach_p[i][j] and can_reach_a[i][j]:
                    res.append([i, j])
        return res

    def __dfs(self, mat, can_reach, r, c):
        if can_reach[r][c]:
            return True
        can_reach[r][c] = True
        for i in range(4):
            x = r + self.DIRNS[i]
            y = c + self.DIRNS[i + 1]
            if (x >= 0 and x < len(mat) and
                y >= 0 and y < len(mat[0]) and
                mat[r][c] <= mat[x][y]):
                self.__dfs(mat, can_reach, x, y)

        
# @lc code=end

