#
# @lc app=leetcode id=1443 lang=python3
#
# [1443] Minimum Time to Collect All Apples in a Tree
#
from typing import *

# @lc code=start
class Solution:
    # T: O(V + E) = O(n) ?
    # S: O(V + E) = O(n) ?
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        G = [[] for _ in range(n)]
        for u, v in edges:
            G[u].append(v)
            G[v].append(u)
        vis = [False] * n
        vis[0] = True
        return Solution.dfs(0, hasApple, G, vis)

    @staticmethod
    def dfs(cur: int, hasApple: List[bool], G: List[List[int]], vis: List[bool]):
        ans = 0
        for next_node in G[cur]:
            if vis[next_node]:
                continue
            vis[next_node] = True
            ans += Solution.dfs(next_node, hasApple, G, vis)
        if cur != 0 and (ans > 0 or hasApple[cur]):
            ans += 2
        return ans

# @lc code=end

