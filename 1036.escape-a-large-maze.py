#
# @lc app=leetcode id=1036 lang=python3
#
# [1036] Escape a Large Maze
#
from collections import deque
from typing import *

# @lc code=start
# Key idea: limit iterations and boundaries of search, 
# assuming no. of blocked points is much smaller than search space
MAX_ITER = 20000
BOUND = 1000000   # sx, sy, tx, ty < 1e6
D = (1, 0, -1, 0, 1)

class Solution:
    # Solution 1: limited DFS
    # T: O(MAX_ITER)
    # S: O(MAX_ITER)
    def isEscapePossible(self, blocked: List[List[int]], source: List[int], target: List[int]) -> bool:
        blocked = set(tuple(b) for b in blocked)

        def dfs(src, dst, vis) -> bool:
            x, y = src
            if not (0 <= x < BOUND and 0 <= y < BOUND) or src in blocked or src in vis:
                return False
            
            vis.add(src)
            if len(vis) > MAX_ITER or src == dst:
                return True
            
            for d in range(4):
                nx = x + D[d]
                ny = y + D[d + 1]
                if dfs((nx, ny), dst, vis):
                    return True

            return False

        source = tuple(source)
        target = tuple(target)

        # improve correctness probability
        return dfs(source, target, set()) and dfs(target, source, set())
    
    # Solution 2: limited BFS
    # T: O(MAX_ITER)
    # S: O(MAX_ITER)

# @lc code=end

