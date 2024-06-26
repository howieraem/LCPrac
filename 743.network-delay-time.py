#
# @lc app=leetcode id=743 lang=python3
#
# [743] Network Delay Time
#
from cmath import inf
import heapq
from typing import List

# @lc code=start
class Solution:
    # Dijkstra's algorithm
    # T: O(V * log(V) + E), V := n, E := len(times)
    # S: O(V + E)
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        # Build graph, converting node ids from 1-indexed to 0-indexed
        graph = [[] for _ in range(n)]
        for u, v, w in times:
            graph[u - 1].append((v - 1, w))
        k -= 1

        dist_to_node = [inf] * n
        dist_to_node[k] = 0

        pq = []
        heapq.heappush(pq, (0, k))  # heapq implements min-heap

        while len(pq):
            _, u = heapq.heappop(pq)    # poll the edge with the least weight (time)
            for v, w in graph[u]:   # O(E)
                if dist_to_node[u] + w < dist_to_node[v]:
                    # Only visit if new distance is less
                    dist_to_node[v] = dist_to_node[u] + w
                    heapq.heappush(pq, (dist_to_node[v], v))    # O(log(V))?

        ans = max(dist_to_node)  # O(V)
        return ans if ans < inf else -1  # if -1, some nodes are not reachable


# @lc code=end

