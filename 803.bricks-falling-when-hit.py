#
# @lc app=leetcode id=803 lang=python3
#
# [803] Bricks Falling When Hit
#
from typing import List

# @lc code=start
class UF:
    def __init__(self, n: int):
        self.parents = [i for i in range(n)]
        self.sizes = [1] * n

    def union(self, p: int, q: int):
        root_p, root_q = self.find(p), self.find(q)
        if root_p != root_q:
            # Rebalancing, avoid degradation to linked list
            if self.sizes[root_p] > self.sizes[root_q]:
                self.parents[root_q] = root_p
                self.sizes[root_p] += self.sizes[root_q]
            else:
                self.parents[root_p] = root_q
                self.sizes[root_q] += self.sizes[root_p]

    def find(self, p: int) -> int:
        # With path compression
        while p != self.parents[p]:
            self.parents[p] = self.parents[self.parents[p]]
            p = self.parents[p]
        return p

class Solution:
    # T: O(m * n * a(m * n)), a() := inverse Ackermann function
    # S: O(m * n)
    def hitBricks(self, grid: List[List[int]], hits: List[List[int]]) -> List[int]:
        m = len(grid)
        n = len(grid[0])
        D = (0, -1, 0, 1, 0)

        uf = UF(m * n + 1)

        # Mark hits
        for (r, c) in hits:
            if grid[r][c] == 1:
                grid[r][c] = 2

        # Util func to connect neighbor bricks
        def union_around(r, c):
            pos = r * n + c + 1
            for d in range(4):
                nr = r + D[d]
                nc = c + D[d + 1]
                if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == 1:
                    new_pos = nr * n + nc + 1
                    uf.union(pos, new_pos)

            if r == 0:  # connect to the top if at the top
                uf.union(0, pos)
        
        # Connect bricks. A brick will not drop if it connects to top or its adjacent bricks will not drop.
        # That is, the brick will not drop if it belongs to the same connected component with the top.
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    union_around(i, j)

        n_bricks_remain = uf.sizes[uf.find(0)]
        res = [0] * len(hits)

        # Instead of checking all cells after each hit, we start from the last hit to the first hit, 
        # restoring it and observing the change of n_bricks_remain which is actually the corresponding 
        # bricks erased. The change of n_bricks_remain equals the change of uf.sizes[uf.find(0)].
        for i in range(len(hits) - 1, -1, -1):
            r, c = hits[i]
            if grid[r][c] == 2:
                union_around(r, c)
                new_n_bricks_remain = uf.sizes[uf.find(0)]
                res[i] = max(0, new_n_bricks_remain - n_bricks_remain - 1)
                n_bricks_remain = new_n_bricks_remain
                grid[r][c] = 1  # restore original data
        return res

        
# @lc code=end

