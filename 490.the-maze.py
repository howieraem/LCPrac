#
# @lc app=leetcode id=490 lang=python3
#
# [490] The Maze
#
from collections import deque
from typing import *

# @lc code=start
class Solution:
    def hasPath(self, maze: List[List[int]], start: List[int], destination: List[int]) -> bool:
        D = (1, 0, -1, 0, 1)
        m = len(maze)
        n = len(maze[0])

        q = deque()
        q.append(start)

        while len(q):
            # l = len(q)
            # for _ in range(l):
                r, c = q.popleft()
                maze[r][c] = 2  # mark visited

                for k in range(4):
                    nr, nc = r, c
                    dr, dc = D[k], D[k + 1]

                    # Keep rolling in the same direction until hitting a wall
                    while 0 <= nr < m and 0 <= nc < n and maze[nr][nc] != 1:
                        nr += dr
                        nc += dc

                    # Go back one step because of the termination condition above
                    nr -= dr
                    nc -= dc

                    if nr == destination[0] and nc == destination[1]:
                        return True

                    if not maze[nr][nc]:
                        q.append((nr, nc))

        return False
                    
# @lc code=end
