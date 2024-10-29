#
# @lc app=leetcode id=2242 lang=python3
#
# [2242] Maximum Score of a Node Sequence
#
import heapq
from typing import List

# @lc code=start
class Solution:
    # T: O(V + E * k ^ 2), V := len(scores), E := len(edges), k := 3 (see explanations below)
    # S: O(V * k)
    def maximumScore(self, scores: List[int], edges: List[List[int]]) -> int:
        L = 4
        graph = [[] for _ in range(len(scores))]  # k: node, v: heap, neighbors with top scores

        # For each edge (i, j), need to find a neighbor of i and a neighbor of j to form 
        # a sequence of length 4.
        # When building the graph, keep only neighbors of the top-3 scores for each node.
        # Reasons for 3 neighbors rather than 2: 
        # 1. One neighbor of i may have the same score as j (and similar for j)
        # 2. One large-score neighbor can be a common neighbor of both i and j
        # For longer sequences, need to determine another number of neighbors to store.
        for i, j in edges:
            # Undirected graph, add both i->j and j->i to graph.
            # Use min heaps and pop if greater than 3 neighbors, 
            # so that the node neighbors end up with the top-3
            heapq.heappush(graph[i], (scores[j], j))
            if len(graph[i]) > L - 1:
                heapq.heappop(graph[i])
            heapq.heappush(graph[j], (scores[i], i))
            if len(graph[j]) > L - 1:
                heapq.heappop(graph[j])

        ans = -1   # return -1 if no such seq exists
        # try expanding the sequence based on every edge
        for i, j in edges:
            for neighbor_i_score, neighbor_i in graph[i]:
                if neighbor_i == j:
                    continue
                for neighbor_j_score, neighbor_j in graph[j]:
                    if neighbor_i != neighbor_j and neighbor_j != i:
                        ans = max(
                                ans, 
                                scores[i] + scores[j] + neighbor_i_score + neighbor_j_score)
        
        return ans

# @lc code=end

