#
# @lc app=leetcode id=1697 lang=python3
#
# [1697] Checking Existence of Edge Length Limited Paths
#
from asyncio import QueueEmpty
from typing import *

# @lc code=start
class DSU:
    def __init__(self, n: int):
        self.parents = list(range(n))
        self.ranks = [0] * n

    def union(self, p: int, q: int) -> bool:
        root_p, root_q = self.find(p), self.find(q)
        if root_p != root_q:
            if self.ranks[root_p] > self.ranks[root_q]:
                self.parents[root_q] = root_p
                self.ranks[root_p] += 1
            else:
                self.parents[root_p] = root_q

    def find(self, p: int) -> int:
        while p != self.parents[p]:
            self.parents[p] = self.parents[self.parents[p]]
            p = self.parents[p]
        return p

class Solution:
    # T: O(E * log(E) + Q * log(Q)), E := len(edgeList), Q := len(queries)
    # S: O(n)
    def distanceLimitedPathsExist(self, n: int, edgeList: List[List[int]], queries: List[List[int]]) -> List[bool]:
        # Trick: sort queries and edges, both based on weight. 
        # Add index to each query to restore result order.
        queries = sorted((w, p, q, i) for i, (p, q, w) in enumerate(queries))
        edgeList = sorted((w, u, v) for u, v, w in edgeList)

        uf = DSU(n)

        # Scan through queries from lowest to highest weight, and 
        # connect the edges with weight strictly below this limit.
        # Note: time complexity below is O((E + Q) * a(n)) which is less significant than sorting above
        res = [False] * len(queries)
        eid = 0
        for w, p, q, i in queries:
            while eid < len(edgeList) and edgeList[eid][0] < w:
                uf.union(edgeList[eid][1], edgeList[eid][2])
                eid += 1
            res[i] = uf.find(p) == uf.find(q)
        return res

# @lc code=end

