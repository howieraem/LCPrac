from typing import List


class Solution:
    # T: O(n), n := len(edges)
    # S: O(n)
    def treeDiameter(self, edges: List[List[int]]) -> int:
        n = len(edges) + 1   # tree, connected graph
        graph = [[] for _ in range(n)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        ans = 0
        def helper(node: int, parent: int) -> int:  # returns max depth at cur node
            nonlocal ans
            d1 = 0  # first max depth
            d2 = 0  # second max depth
            for child in graph[node]:
                if child == parent:
                    # undirected
                    continue
                d = helper(child, node)
                if d > d1:
                    d2 = d1
                    d1 = d
                elif d > d2:
                    d2 = d
            ans = max(ans, d1 + d2)
            return d1 + 1

        helper(0, -1)

        return ans
