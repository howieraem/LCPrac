#
# @lc app=leetcode id=787 lang=python3
#
# [787] Cheapest Flights Within K Stops
#
from cmath import inf
from heapq import *
from typing import *

# @lc code=start
class Solution:
    # Dijkstra's Algorithm
    # T: O(n^k * log(n^k))
    # S: O(n + e)
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        graph = [[] for _ in range(n)]
        for u, v, w in flights:
            graph[u].append((v, w))

        dist = [(inf, inf)] * n     # list of (cost, hops)
        dist[src] = (0, 0)

        pq = [(0, src, 0)]  # heap of (cost, node, hops)
        while len(pq):
            cost, node, hops = heappop(pq)
            if node == dst and hops <= k + 1:
                return cost
            if hops == k + 1:
                continue

            for v, c in graph[node]:
                new_cost = cost + c
                new_hops = hops + 1
                if new_cost < dist[v][0] or new_hops < dist[v][1]:
                    dist[v] = (new_cost, new_hops)
                    heappush(pq, (new_cost, v, new_hops))
        
        return -1


# @lc code=end

