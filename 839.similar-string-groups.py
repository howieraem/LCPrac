#
# @lc app=leetcode id=839 lang=python3
#
# [839] Similar String Groups
#
from typing import List

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
    # T: O(l * n ^ 2 * a(n)), n := len(strs), l := avg str length, a() := inverse Ackermann func
    # S: O(n)
    def numSimilarGroups(self, strs: List[str]) -> int:
        n = len(strs)
        uf = UF(n)
        for i in range(n):
            for j in range(i + 1, n):
                if self.is_similar(strs[i], strs[j]):
                    uf.union(i, j)
        return uf.cnt

    @staticmethod
    def is_similar(a: str, b: str) -> bool:
        diff = 0
        for c1, c2 in zip(a, b):
            diff += (c1 != c2)
            if diff > 2:
                return False
        return True
        
# @lc code=end

