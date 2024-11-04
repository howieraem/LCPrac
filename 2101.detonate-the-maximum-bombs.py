#
# @lc app=leetcode id=2101 lang=python3
#
# [2101] Detonate the Maximum Bombs
#
from typing import *

# @lc code=start
class Solution:
    # graph DFS
    # T: O(n ^ 3) worse case if all bombs connected (radius >= distance between centers)
    # S: O(n ^ 2) for the graph
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        n = len(bombs)

        # build a directed graph
        graph = [[] for _ in range(n)]
        for i, (x1, y1, r) in enumerate(bombs):
            for j, (x2, y2, _) in enumerate(bombs):
                # check against the larger radius
                if i != j and (x2 - x1) ** 2 + (y2 - y1) ** 2 <= r ** 2:
                    graph[i].append(j)
        
        def dfs(node: int, vis: Set[int]):
            for neighbor in graph[node]:
                if neighbor not in vis:
                    vis.add(neighbor)
                    dfs(neighbor, vis)
        
        # Start dfs from each node and maximize the number of reachable nodes
        ans = 1
        vis = set()
        for i in range(n):
            vis.clear()
            vis.add(i)
            dfs(i, vis)
            # at the end of a DFS, the vis set size means the number of reachable nodes from the starting node
            ans = max(ans, len(vis))

        return ans
    
    # NOTE: Union find won't work because the graph is directed (i.e., one circle covering another one doesn't mean the opposite). 
    # Example: https://assets.leetcode.com/users/images/d918d62e-b7ff-43e7-be94-2ee3a2f84c7c_1711417630.7414768.png


# @lc code=end

