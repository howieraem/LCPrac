from typing import List

class UF:
    # S: O(m * n)
    def __init__(self, m: int, n: int) -> None:
        self.cnt = 0
        self.total = m * n
        self.m = m
        self.n = n
        self.parents = [-1] * self.total

        # Store how many nodes are connected to each node, 
        # which is used in connecting two nodes to avoid 
        # degration to linked list
        self.sizes = [0] * self.total

    # With rebalancing, T is O(log(m * n))
    def union(self, p: int, q: int) -> bool:
        root_p, root_q = self.find(p), self.find(q)
        if root_p == root_q:
            return

        # Rebalancing, avoid degration to linked list
        if self.sizes[root_p] > self.sizes[root_q]:
            self.parents[root_q] = root_p
            self.sizes[root_p] += self.sizes[root_q]
        else:
            self.parents[root_p] = root_q
            self.sizes[root_q] += self.sizes[root_p]

        self.cnt -= 1

    # With path compression, T can be reduced to O(1) eventually
    def find(self, p: int) -> int:
        while p != self.parents[p]:
            self.parents[p] = self.parents[self.parents[p]]
            p = self.parents[p]
        return p

    # T: O(1)
    def add(self, x: int, y: int) -> int:
        if not (0 <= x < self.m and 0 <= y < self.n):
            return -1
        p = x * self.n + y
        if self.parents[p] >= 0:
            # already added
            return -1
        self.parents[p] = p
        self.sizes[p] = 1
        self.cnt += 1
        return p

    # T: O(1)
    def find_2d(self, x: int, y: int) -> bool:
        if not (0 <= x < self.m and 0 <= y < self.n):
            return -1
        p = x * self.n + y
        return self.parents[p]


DIRN = (0, -1, 0, 1, 0)


class Solution:
    # T: O(len(positions) * log(m * n))
    # S: O(m * n)
    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        uf = UF(m, n)
        res = [0] * len(positions)
        for i, (x, y) in enumerate(positions):
            p = uf.add(x, y)
            if p >= 0:  # exclude bad/duplicate input data
                for d in range(4):
                    q = uf.find_2d(x + DIRN[d], y + DIRN[d + 1])
                    if q >= 0:  # added as a valid land before
                        uf.union(p, q)
            res[i] = uf.cnt

        return res
