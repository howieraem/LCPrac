#
# @lc app=leetcode id=1197 lang=python3
#
# [1197] Minimum Knight Moves
#
from collections import deque

# @lc code=start
class Solution:
    # T: O(abs(x) * abs(y))
    # S: O(abs(x) * abs(y))
    def minKnightMoves(self, x: int, y: int) -> int:
        D = ((2, 1), (1, 2), (-1, 2), (-2, 1), (-2, -1), (-1, -2), (1, -2), (2, -1))
        
        # Because of symmetry, try to limit the problem space to the 1st quadrant
        x = abs(x)
        y = abs(y)

        q = deque()
        vis = set()
        origin = (0, 0)
        q.append(origin)
        vis.add(origin)

        ans = 0
        while len(q):
            qs = len(q)
            for _ in range(qs):
                r, c = q.popleft()
                if r == x and c == y:
                    return ans
                for dr, dc in D:
                    nr = r + dr
                    nc = c + dc
                    npos = (nr, nc)
                    # IMPORTANT: (0, 0) cannot reach (1, 1) optimally if 
                    # not going via (2, -1) or (-1, 2). Thus, the lower 
                    # bound should be -1.
                    if nr >= -1 and nc >= -1 and npos not in vis:
                        q.append(npos)
                        vis.add(npos)
            ans += 1
        return -1

# @lc code=end

