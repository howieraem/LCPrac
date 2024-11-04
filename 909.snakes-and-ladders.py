#
# @lc app=leetcode id=909 lang=python3
#
# [909] Snakes and Ladders
#
from collections import deque
from typing import *

# @lc code=start
class Solution:
    # BFS
    # T: O(n ^ 2)
    # S: O(n ^ 2)
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        target = n * n - 1  # zero indexed

        q = deque()
        q.append(0)  # zero indexed
        vis = [False] * (n * n)
        steps = 0

        def get_board_val(cur):
            r, c = divmod(cur, n)
            row = n - 1 - r
            col = c if (r & 1) == 0 else n - 1 - c
            return board[row][col]

        while len(q) > 0:
            qs = len(q)          
            for _ in range(qs):
                cur = q.popleft()
                
                for nxt in range(cur + 1, min(cur + 7, n * n)):
                    v = get_board_val(nxt)

                    # IMPORTANT: jump straight to the ladder/snake's destination,
                    # to avoid tracking the number of ladders and snakes
                    if v != -1:
                        nxt = v - 1  # zero indexed
                    
                    if nxt == target:
                        return steps + 1
                    
                    if not vis[nxt]:
                        q.append(nxt)
                        vis[nxt] = True
            
            steps += 1

        return -1


# @lc code=end

