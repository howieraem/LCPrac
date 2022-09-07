#
# @lc app=leetcode id=947 lang=python3
#
# [947] Most Stones Removed with Same Row or Column
#
from typing import *

# @lc code=start
class UF:
    def __init__(self, n: int):
        self.cnt = n
        self.parents = [i for i in range(n)]
        self.sizes = [1] * n

    def union(self, p: int, q: int) -> bool:
        root_p, root_q = self.find(p), self.find(q)
        if root_p != root_q:
            if self.sizes[root_p] > self.sizes[root_q]:
                self.parents[root_q] = root_p
                self.sizes[root_p] += self.sizes[root_q]
            else:
                self.parents[root_p] = root_q
                self.sizes[root_q] += self.sizes[root_p]
            self.cnt -= 1

    def find(self, p: int) -> int:
        while p != self.parents[p]:
            self.parents[p] = self.parents[self.parents[p]]
            p = self.parents[p]
        return p

class Solution:
    # T: O(n ^ 2 * a(n)), a() := inverse Ackermann func
    # S: O(n)
    def removeStones(self, stones: List[List[int]]) -> int:
        # Prerequisite: no duplicate stones
        n = len(stones)
        uf = UF(n)

        for i in range(n):
            for j in range(i + 1, n):
                if stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]:
                    uf.union(i, j)

        # Only the root parents will remain at the end
        return n - uf.cnt

# @lc code=end

