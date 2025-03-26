#
# @lc app=leetcode id=797 lang=python3
#
# [797] All Paths From Source to Target
#
from typing import List

# @lc code=start
class Solution:
    # DFS + backtracking + graph
    # T: O(n * 2 ^ n)
    # S: O(n)
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        n = len(graph)
        res = []

        def dfs(node, path):
            if node == n - 1:
                res.append(path)
                # res.append(path[:])
                return
            
            for neighbor in graph[node]:
                # path.append(neighbor)
                dfs(neighbor, path + [neighbor])
                # path.pop()

        dfs(0, [0])
        return res

# @lc code=end

