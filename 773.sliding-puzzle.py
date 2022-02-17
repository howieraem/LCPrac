#
# @lc app=leetcode id=773 lang=python3
#
# [773] Sliding Puzzle
#
from collections import deque
from typing import *

# @lc code=start
class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        M, N = 2, 3

        # If M and N are variable, need to do 
        # extra to get the next indexes and
        # the final state
        NEIGHBOR_I = [
            [1, 3],
            [0, 2, 4],
            [1, 5],
            [0, 4],
            [3, 1, 5],
            [4, 2]
        ]
        FINAL = "123450"

        state = []
        for i in range(M):
            for j in range(N):
                state.append(str(board[i][j]))

        state = "".join(state)
        if state == FINAL:
            return 0

        q = deque()
        vis = set()
        q.append(state)
        vis.add(state)
        moves = 0

        while len(q):
            l = len(q)
            for _ in range(l):
                s: str = q.popleft()
                idx0 = s.index('0')
                for ni in NEIGHBOR_I[idx0]:
                    ns = list(s)
                    ns[idx0], ns[ni] = ns[ni], ns[idx0]
                    ns = "".join(ns)

                    if ns == FINAL:
                        return moves + 1
                    if ns not in vis:
                        q.append(ns)
                        vis.add(ns)
            moves += 1
        
        return -1

# @lc code=end

