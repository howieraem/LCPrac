#
# @lc app=leetcode id=1168 lang=python3
#
# [1168] Optimize Water Distribution in a Village
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
        # degration to linked list
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
    # Graph + union find / disjoint set union
    # Minimum spanning tree (MST), Kruskal's algorithm
    # T: O(V + E * log(E))
    # S: O(V + E)
    def minCostToSupplyWater(self, n: int, wells: List[int], pipes: List[List[int]]) -> int:
        # Trick to deal with wells: add a dummy graph node, and treat
        # wells as pipes from dummy node to actual graph nodes, so 
        # add 1 to UF. 
        # Also note that houses in `pipes` are already 1-indexed.
        uf = UF(n + 1)

        for i, w in enumerate(wells):
            # dummy graph node is 0; other nodes are regarded as 1-indexed.
            pipes.append([0, i + 1, w])

        # sort by cost ASC
        pipes.sort(key=lambda p: p[2])

        ans = 0
        for u, v, cost in pipes:
            if uf.union(u, v):
                ans += cost
            
            if uf.cnt == 1:
                # all connected
                break

        return ans


# @lc code=end

