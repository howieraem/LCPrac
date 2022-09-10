#
# @lc app=leetcode id=684 lang=python3
#
# [684] Redundant Connection
#
from typing import *

# @lc code=start
class UF:
    # S: O(n)
    def __init__(self, n: int):
        self.cnt = n
        self.parents = list(range(n))
        self.sizes = [1] * n

    # With rebalancing, T is O(log(n))
    def union(self, p: int, q: int) -> bool:
        root_p, root_q = self.find(p), self.find(q)
        if root_p == root_q:
            # Already connected
            return False

        # Rebalancing, avoid degration to linked list
        if self.sizes[root_p] > self.sizes[root_q]:
            self.parents[root_q] = root_p
            self.sizes[root_p] += self.sizes[root_q]
        else:
            self.parents[root_p] = root_q
            self.sizes[root_q] += self.sizes[root_p]

        self.cnt -= 1
        return True

    # With path compression, T can be reduced to O(1) eventually
    def find(self, p: int) -> int:
        while p != self.parents[p]:
            self.parents[p] = self.parents[self.parents[p]]
            p = self.parents[p]
        return p

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        uf = UF(len(edges) + 1)  # add 1 for 1-indexed
        for e in edges:
            if not uf.union(e[0], e[1]):
                return e
        return []

# @lc code=end

