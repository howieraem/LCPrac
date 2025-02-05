#
# @lc app=leetcode.cn id=399 lang=python3
#
# [399] 除法求值
#
from collections import defaultdict
from typing import *

# @lc code=start
class Solution:
    # Graph + DFS / backtracking
    # T: O(V + E + Q)
    # S: O(V + E)
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        # 构造图，equations的第一项除以第二项等于value里的对应值，第二项除以第一项等于其倒数
        graph = defaultdict(dict)  # k: numerator, v: {denominator: calculation value}
        for (x, y), v in zip(equations, values):
            # undirected graph
            graph[x][y] = v
            graph[y][x] = 1 / v
        
        # dfs找寻从s到t的路径并返回结果叠乘后的边权重即结果
        def dfs(s: str, t: str, visited: Set[int]) -> int:
            for node in graph[s].keys():
                if node == t:
                    return graph[s][node]
                elif node not in visited:
                    visited.add(node)  # 添加到已访问避免重复遍历
                    v = dfs(node, t, visited)
                    if v != -1:   # child value can be determined
                        # Math example: s / t = (s / node) * v
                        # where v = (node / t)
                        return graph[s][node] * v
            return -1   # value can't be determined

        # 逐个计算query的值
        res = [-1.0] * len(queries)
        for i, (qs, qt) in enumerate(queries):
            if qs not in graph or qt not in graph:
                continue
            if qs == qt:
                res[i] = 1.0
            else:
                res[i] = dfs(qs, qt, set())
        return res

# @lc code=end

