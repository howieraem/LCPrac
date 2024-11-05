#
# @lc app=leetcode id=529 lang=python3
#
# [529] Minesweeper
#
from collections import deque
from typing import *

# @lc code=start
# IMPORTANT: max. eight neighbors per cell
D = (
    (0, 1),
    (1, 0),
    (1, 1),
    (0, -1),
    (-1, 0),
    (-1, -1),
    (1, -1),
    (-1, 1)
)

class Solution:
    '''
    # Solution 1: DFS
    # T: O(m * n)
    # S: O(m * n)
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        m = len(board)
        if m == 0:
            return board
        n = len(board[0])
        if n == 0:
            return board
        
        r, c = click
        if not (0 <= r < m and 0 <= c < n):
            return board
        
        if board[r][c] == 'M':
            board[r][c] = 'X'
            return board

        # board[r][c] == 'E'
        # Check surrounding mines
        cnt = 0
        for dr, dc in D:
            nr = r + dr
            nc = c + dc
            if 0 <= nr < m and 0 <= nc < n:
                cnt += (board[nr][nc] == 'M' or board[nr][nc] == 'X')
        
        if cnt > 0:
            board[r][c] = str(cnt)
        else:   # Do DFS on adjacent cells
            board[r][c] = 'B'
            for dr, dc in D:
                nr = r + dr
                nc = c + dc
                if 0 <= nr < m and 0 <= nc < n and board[nr][nc] == 'E':
                    # IMPORTANT: simulate a click recursively
                    self.updateBoard(board, [nr, nc])
        return board
    '''

    # Solution 2: BFS
    # T: O(m * n)
    # S: O(m * n)
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        m = len(board)
        if m == 0:
            return board
        n = len(board[0])
        if n == 0:
            return board
        
        r, c = click
        if not (0 <= r < m and 0 <= c < n):
            return board
        
        q = deque()
        q.append((r, c))

        while len(q) > 0:
            r, c = q.popleft()

            if board[r][c] == 'M':
                board[r][c] = 'X'
                continue

            # board[r][c] == 'E'
            # Check surrounding mines
            cnt = 0
            for dr, dc in D:
                nr = r + dr
                nc = c + dc
                if 0 <= nr < m and 0 <= nc < n:
                    cnt += (board[nr][nc] == 'M' or board[nr][nc] == 'X')
            
            if cnt > 0:
                board[r][c] = str(cnt)
            else:   # Do DFS on adjacent cells
                board[r][c] = 'B'
                for dr, dc in D:
                    nr = r + dr
                    nc = c + dc
                    if 0 <= nr < m and 0 <= nc < n and board[nr][nc] == 'E':
                        q.append((nr, nc))

                        # IMPORTANT: mark visited, avoid being pushed to the queue again
                        board[nr][nc] = 'B'
        
        return board

# @lc code=end

