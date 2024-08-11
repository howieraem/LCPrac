from collections import defaultdict
from typing import List

class Solution:
    def countGoodNodes(self, edges: List[List[int]]) -> int:
        tree = defaultdict(list)
        for a, b in edges:  # undirected graph
            tree[a].append(b)
            tree[b].append(a)

        ans = 0

        def dfs(node, parent):
            nonlocal ans
            total_size = 1
            subtree_sizes = defaultdict(int)
            for child in tree[node]:
                if child != parent:
                    subtree_size = dfs(child, node)
                    total_size += subtree_size
                    subtree_sizes[subtree_size] += 1
            ans += (len(subtree_sizes) <= 1)   # leaf nodes have no subtree
            return total_size

        dfs(0, -1)   # 0 <= node < N

        return ans
