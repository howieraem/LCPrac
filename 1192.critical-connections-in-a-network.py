#
# @lc app=leetcode id=1192 lang=python3
#
# [1192] Critical Connections in a Network
#
from typing import *

# @lc code=start
class Solution:
    # T: O(V + E)
    # S: O(V + E)
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        A = [[] for _ in range(n)]
        # "Rank" means the order of DFS level
        lowestRanks = [0] * n
        for u, v in connections:
            A[u].append(v)
            A[v].append(u)
        return Solution.dfs(1, 0, -1, A, lowestRanks)

    @staticmethod
    def dfs(rank, cur, pre, A, lowestRanks):
        res = []
        lowestRanks[cur] = rank
        for neighbor in A[cur]:
            if neighbor == pre:
                continue
            if not lowestRanks[neighbor]:  # not visited
                res.extend(Solution.dfs(rank + 1, neighbor, cur, A, lowestRanks))
            lowestRanks[cur] = min(lowestRanks[cur], lowestRanks[neighbor])
            if lowestRanks[neighbor] == rank + 1:
                res.append([cur, neighbor])
        return res


# @lc code=end

