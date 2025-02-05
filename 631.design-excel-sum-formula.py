#
# @lc app=leetcode id=631 lang=python3
#
# [631] Design Excel Sum Formula
#
from collections import defaultdict
from typing import *

# @lc code=start
# Hash Map
# S: O(h * w)
OFFSET = ord('A')

class Excel:
    # T: O(h * w)
    def __init__(self, height: int, width: str):
        # each cell: {'v': val, 'sum': list of associated cells {k: (r, c), v: cell freq}}
        self.table: List[List[Dict]] = \
                [[{'v': 0, 'sum': None} for _ in range(ord(width) - OFFSET + 1)] 
                 for _ in range(height)]

    def __pos(self, r: int, c: str) -> Tuple[int, int]:
        r -= 1
        c = ord(c) - OFFSET
        if 0 <= r < len(self.table) and 0 <= c < len(self.table[0]):
            return r, c
        return -1, -1

    # T: O(1)
    def set(self, row: int, column: str, val: int) -> None:
        r, c = self.__pos(row, column)
        if r >= 0 and c >= 0:
            self.table[r][c] = {'v': val, 'sum': None}

    # T: O(h * w)
    def get(self, row: int, column: str) -> int:
        r, c = self.__pos(row, column)
        if r < 0 or c < 0:
            return 0
        cell = self.table[r][c]
        associated_cells = cell.get('sum', None)
        if associated_cells is None:
            return cell['v']
        return sum(self.get(*pos) * freq for pos, freq in associated_cells.items())

    # T: O(h * w)
    def sum(self, row: int, column: str, numbers: List[str]) -> int:
        r, c = self.__pos(row, column)
        if r < 0 or c < 0:
            return 0
        
        associated_cells = defaultdict(int)
        for cell_id in numbers:
            if cell_id == '':
                continue
            parts = cell_id.split(':')
            if len(parts) == 1:
                s_row, s_col = int(parts[0][1:]), parts[0][0]
                associated_cells[(s_row, s_col)] += 1
            elif len(parts) == 2:
                s_row, s_col = int(parts[0][1:]), parts[0][0]
                e_row, e_col = int(parts[1][1:]), parts[1][0]

                for i in range(s_row, e_row + 1):
                    for j in range(ord(s_col) - OFFSET, (ord(e_col) - OFFSET) + 1):
                        associated_cells[(i, chr(j + OFFSET))] += 1

        self.table[r][c]['sum'] = associated_cells
        return self.get(row, column)
        


# Your Excel object will be instantiated and called as such:
# obj = Excel(height, width)
# obj.set(row,column,val)
# param_2 = obj.get(row,column)
# param_3 = obj.sum(row,column,numbers)
# @lc code=end

