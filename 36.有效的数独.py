#
# @lc app=leetcode.cn id=36 lang=python3
#
# [36] 有效的数独
#
from typing import List
from pprint import pprint

# @lc code=start
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_num_counts = [[0]*9 for _ in range(9)]
        col_num_counts = [[0]*9 for _ in range(9)]
        subgrid_num_counts = [[0]*9 for _ in range(9)]
        for i in range(9):
            for j in range(9):
                num = board[i][j]   # or [j][i]
                if num == '.':
                    continue
                num = int(num)
                num_idx = num-1
                subgrid_idx = 3*(i//3)+j//3
                row_num_counts[i][num_idx] += 1
                col_num_counts[j][num_idx] += 1
                subgrid_num_counts[subgrid_idx][num_idx] += 1
                if row_num_counts[i][num_idx] > 1 or \
                    col_num_counts[j][num_idx] > 1 or \
                    subgrid_num_counts[subgrid_idx][num_idx] > 1:
                        return False
        return True
        

# @lc code=end
