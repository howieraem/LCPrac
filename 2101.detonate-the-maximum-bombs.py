#
# @lc app=leetcode id=2101 lang=python3
#
# [2101] Detonate the Maximum Bombs
#
from typing import *

# @lc code=start
class Solution:
    # T: O(n ^ 3) worse case if all bombs connected (radius > distance between centers)
    # S: O(n ^ 2) for the graph
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        n = len(bombs)

        # build a directed graph
        graph = [[] for _ in range(n)]
        for i, (x1, y1, r) in enumerate(bombs):
            for j, (x2, y2, _) in enumerate(bombs):
                if i != j and (x2 - x1) ** 2 + (y2 - y1) ** 2 <= r ** 2:
                    graph[i].append(j)
        
        def dfs(node: int, vis: Set[int]):
            for neighbor in graph[node]:
                if neighbor not in vis:
                    vis.add(neighbor)
                    dfs(neighbor, vis)
        
        # Start dfs from each node and find the number of reachable nodes
        ans = 1
        vis = set()
        for i in range(n):
            vis.clear()
            vis.add(i)
            dfs(i, vis)
            ans = max(ans, len(vis))

        return ans


# @lc code=end

