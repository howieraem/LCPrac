#
# @lc app=leetcode id=847 lang=python3
#
# [847] Shortest Path Visiting All Nodes
#
from collections import deque
from typing import *

# @lc code=start
class Solution:
    # T: O(n ^ 2 * 2 ^ n), worse case n * 2 ^ n states
    # S: O(n * 2 ^ n)
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n = len(graph)

        # state: (node id, bitmask of visited nodes, path length)
        # The bitmask of visited nodes is not the same as visited states,
        # because a node can be visited more than once to get the 
        # shortest path visiting all nodes.
        q = deque()
        vis_states = set()

        # Initially, we start from each graph node
        for i in range(n):
            vis_node_mask = (1 << i)
            state = (i, vis_node_mask, 0)
            q.append(state)
            vis_states.add(state)
        
        while len(q):
            qs = len(q)
            for _ in range(qs):
                node, mask, path_len = q.popleft()
                if mask == (1 << n) - 1:
                    # all nodes visited
                    return path_len
                for next_node in graph[node]:
                    new_state = (next_node, mask | (1 << next_node), path_len + 1)
                    if new_state not in vis_states:
                        q.append(new_state)
                        vis_states.add(new_state)
        return -1

# @lc code=end

