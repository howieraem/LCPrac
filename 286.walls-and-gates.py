#
# @lc app=leetcode id=286 lang=python3
#
# [286] Walls and Gates
#
from collections import deque
from typing import *

# @lc code=start
class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        D = (1, 0, -1, 0, 1)
        m = len(rooms)
        n = len(rooms[0])
        q = deque()
        vis = set()
        for i in range(m):
            for j in range(n):
                if rooms[i][j] == 0:
                    vis.clear()
                    q.append((i, j))
                    dist = 0
                    while len(q):
                        l = len(q)
                        for _ in range(l):
                            r, c = q.popleft()
                            rooms[r][c] = min(rooms[r][c], dist)

                            for k in range(4):
                                p = (r + D[k], c + D[k + 1])
                                if 0 <= p[0] < m and 0 <= p[1] < n and rooms[p[0]][p[1]] > 0 and p not in vis:
                                    q.append(p)
                                    vis.add(p)
                        dist += 1
                    
        return rooms

        
# @lc code=end

