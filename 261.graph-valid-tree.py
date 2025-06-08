#
# @lc app=leetcode id=261 lang=python3
#
# [261] Graph Valid Tree
#
from typing import *

# @lc code=start
class UF:
    # S: O(n)
    def __init__(self, n: int):
        self.cnt = n
        self.parents = list(range(n))

        # Store how many nodes are connected to each node, 
        # which is used in connecting two nodes to avoid 
        # degradation to linked list
        self.sizes = [1] * n

    # With rebalancing, T is O(log(n))
    def union(self, p: int, q: int) -> bool:
        root_p, root_q = self.find(p), self.find(q)
        if root_p == root_q:
            # Already connected
            return False

        # Rebalancing, avoid degradation to linked list
        # connect smaller subgraph to the larger one
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
    # T: O(V + E*log(E)), V := n, E := len(edges)
    # S: O(V)
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        uf = UF(n)  
        for p, q in edges:
            if not uf.union(p, q):
                # If p and q are already connected,
                # then there must exist a cycle
                return False
        return uf.cnt == 1  # check if fully connected (if no, a forest)

# @lc code=end

