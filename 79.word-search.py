#
# @lc app=leetcode id=79 lang=python3
#
# [79] Word Search
#
from typing import List

# @lc code=start
class Solution:
    D = (0, 1, 0, -1, 0)

    # T: O(m * n * 3 ^ l), l := len(word)
    # S: O(l)
    def exist(self, board: List[List[str]], word: str) -> bool:
        for r in range(len(board)):  # O(m)
            for c in range(len(board[r])):  # O(n)
                if self.backtrack(board, r, c, word, 0):  # O(3 ^ l)
                    return True
        return False

    @staticmethod
    def backtrack(board, r, c, word, i):
        if i == len(word):
            return True
        
        if r < 0 or r == len(board) or c < 0 or c == len(board[r]) or board[r][c] != word[i]:
            return False
        
        tmp = board[r][c]
        board[r][c] = '*'  # mark visited
        for k in range(4):
            if Solution.backtrack(board, r + Solution.D[k], c + Solution.D[k + 1], word, i + 1):
                return True
        board[r][c] = tmp  # undo
        return False

# @lc code=end

