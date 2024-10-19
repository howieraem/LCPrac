#
# @lc app=leetcode id=785 lang=python3
#
# [785] Is Graph Bipartite?
#
from collections import deque
from typing import List

# @lc code=start
class Solution:
    # DFS with coloring
    # T: O(V + E)
    # S: O(V + E)
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        colors = [0] * n  # 0 unvisited, 1 set1, -1 set2

        def dfs(node, cur_color):
            if colors[node] != 0:
                return colors[node] == cur_color
            colors[node] = cur_color
            for nxt in graph[node]:
                if not dfs(nxt, -cur_color):
                    return False
            return True
        
        for i in range(n):
            if colors[i] == 0:
                if not dfs(i, 1):
                    return False
        return True

    # BFS with coloring
    # T: O(V + E)
    # S: O(V + E)
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        colors = [0] * n  # 0 unvisited, 1 set1, -1 set2

        for i in range(n):
            if colors[i] != 0:
                continue
            
            q = deque()
            q.append(i)
            colors[i] = 1

            while len(q) > 0:
                node = q.popleft()
                for nxt in graph[node]:
                    if colors[nxt] == 0:
                        q.append(nxt)
                        colors[nxt] = -colors[node]
                    elif colors[nxt] != -colors[node]:
                        return False

        return True

        
# @lc code=end

