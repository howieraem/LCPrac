#
# @lc app=leetcode.cn id=79 lang=python3
#
# [79] 单词搜索
#
# from typing import List

# @lc code=start
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        n = len(board[0])
        l, lw = len(board)*n, len(word)-1
        
        def track(idx, char_idx):
            r, c = divmod(idx, n)
            curr_char = board[r][c]
            if curr_char != word[char_idx]:
                return False
            if char_idx == lw:
                return True
            board[r][c] = 0     # stop the algorithm going back
            char_idx += 1
            if (
                ((idx+1) % n and track(idx+1, char_idx)) or
                (idx % n and track(idx-1, char_idx)) or
                (idx+n < l and track(idx+n, char_idx)) or
                (idx >= n and track(idx-n, char_idx))
            ):
                return True
            board[r][c] = curr_char   # recover data if path invalid
            return False
        
        for i in range(l):
            if track(i, 0):
                return True
        return False

# @lc code=end
'''
board = [
    ['A', 'B', 'C', 'E'],
    ['S', 'F', 'C', 'S'],
    ['A', 'D', 'E', 'E'],
]
# board = [['a', 'b'], ['c', 'd']]

word = 'ABCCED'
sol = Solution()
print(sol.exist(board, word))
'''
