#
# @lc app=leetcode id=1548 lang=python3
#
# [1548] The Most Similar Path in a Graph
#
from typing import *

# @lc code=start
class Solution:
    # T: O(n ^ 2 * m), m := len(targetPath)
    # S: O(n * m)
    def mostSimilar(self, n: int, roads: List[List[int]], names: List[str], targetPath: List[str]) -> List[int]:
        graph = [[] for _ in range(n)]
        for (u, v) in roads:
            graph[u].append(v)
            graph[v].append(u)

        m = len(targetPath)
        # dp[i][u] means the minimum edit distance for targetPath[:i+1] ending with node u
        dp = [[m] * n for _ in range(m)]

        # for reconstructing path
        pre_nodes = [[0] * n for _ in range(m)]
        
        # calculate the edit distances
        for u in range(n):
            dp[0][u] = names[u] != targetPath[0]
        for i in range(1, m):
            for u in range(n):
                for v in graph[u]:
                    if dp[i - 1][v] < dp[i][u]:
                        dp[i][u] = dp[i - 1][v]
                        pre_nodes[i][u] = v
                dp[i][u] += names[u] != targetPath[i]

        # reconstruct path
        res = [0]
        min_dist = m
        for u in range(n):
            if dp[-1][u] < min_dist:
                min_dist = dp[-1][u]
                res[0] = u
        for i in range(m - 1, 0, -1):
            u = pre_nodes[i][res[-1]]
            res.append(u)
        return res[::-1]

# @lc code=end

