#
# @lc app=leetcode id=323 lang=python3
#
# [323] Number of Connected Components in an Undirected Graph
#
from typing import *

# @lc code=start
class UF:
    def __init__(self, n):
        self.cnt = n
        self.parents = [i for i in range(n)]
        self.sizes = [1] * n

    def find(self, p):
        while p != self.parents[p]:
            self.parents[p] = self.parents[self.parents[p]]
            p = self.parents[p]
        return p

    def union(self, p, q):
        root_p, root_q = self.find(p), self.find(q)
        if root_p != root_q:
            if self.sizes[root_p] > self.sizes[root_q]:
                self.parents[root_q] = root_p
                self.sizes[root_p] += self.sizes[root_q]
            else:
                self.parents[root_p] = root_q
                self.sizes[root_q] += self.sizes[root_p]
            self.cnt -= 1

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        uf = UF(n)
        for u, v in edges:
            uf.union(u, v)
        return uf.cnt

# @lc code=end

