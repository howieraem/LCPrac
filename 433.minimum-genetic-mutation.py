#
# @lc app=leetcode id=433 lang=python3
#
# [433] Minimum Genetic Mutation
#
from collections import deque
from typing import *

# @lc code=start
class Solution:
    # BFS
    # T: O(n ^ 2), n := gene length
    # S: O(n * len(bank)) pruned by bank
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        if startGene == endGene:
            return 0

        bank = set(bank)
        if endGene not in bank:
            return -1

        q = deque()
        q.append(startGene)
        vis = set()
        vis.add(startGene)
        steps = 0

        while len(q) > 0:
            qs = len(q)
            
            for _ in range(qs):
                cur = q.popleft()
                cur = list(cur)  # for in-place char modifications

                for i in range(len(cur)):
                    c = cur[i]
                    
                    for nxt_c in 'ATGC':
                        if nxt_c == c:
                            continue
                        cur[i] = nxt_c
                        nxt = ''.join(cur)
                        if nxt == endGene:
                            return steps + 1

                        if nxt not in vis and nxt in bank:
                            q.append(nxt)
                            vis.add(nxt)
                    
                    cur[i] = c  # limit one mutation per step
            
            steps += 1

        return -1

# @lc code=end

