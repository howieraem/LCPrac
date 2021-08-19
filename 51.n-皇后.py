#
# @lc app=leetcode.cn id=51 lang=python3
#
# [51] N皇后
#

# @lc code=start
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []
        s = "." * n

        def backtrack(i, row, col, diag_tb, diag_bt):
            """
            记录行、列、正对角、负对角，不能有两个以上的棋子。
            如何判断是否在对角上呢？正对角就是相加之和一样的，负对角就是相减之差一样的。
            """
            # while iterating on the rows, prune branches with invalid columns or diagonals
            if i == n:
                res.append(row)
                return 
            for j in range(n):
                if j not in col and i + j not in diag_tb and i - j not in diag_bt:
                    backtrack(i = i + 1, 
                              row = row + [s[:j] + "Q" + s[j+1:]], 
                              col = col | {j},                # Union
                              diag_tb = diag_tb | {i + j},    # Union
                              diag_bt = diag_bt | {i - j})    # Union
            
        backtrack(0, [], set(), set(), set())    
        return res

            

# @lc code=end

