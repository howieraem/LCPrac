from typing import *

class Solution:
    # Graph + DFS
    # T: O(V + E)
    # S: O(V + E)
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        g = [[] for _ in range(n)]
        for u, v in edges:
            # undirected graph
            g[u].append(v)
            g[v].append(u)

        vis = set()

        def dfs(u: int, subgraph_info: List[int]):
            vis.add(u)
            subgraph_info[0] += 1   # no. of nodes in subgraph/component
            subgraph_info[1] += len(g[u])  # no. of edges in subgraph/component

            for v in g[u]:
                if v not in vis:
                    dfs(v, subgraph_info)

        ans = 0
        for u in range(n):
            if u not in vis:
                subgraph_info = [0, 0]
                dfs(u, subgraph_info)

                # Complete connected component: V * (V - 1) = E
                ans += subgraph_info[0] * (subgraph_info[0] - 1) == subgraph_info[1]

        return ans
