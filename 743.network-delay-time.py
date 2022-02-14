#
# @lc app=leetcode id=743 lang=python3
#
# [743] Network Delay Time
#
import heapq
from typing import List

# @lc code=start
class Solution:
    # T: O(V + E*log(V)), V := n, E := len(times)
    # S: O(V + E)
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = [[] for _ in range(n + 1)]
        for u, v, w in times:
            graph[u].append((v, w))

        inf = float('inf')
        dist = [inf] * n
        dist[k - 1] = 0

        pq = []
        heapq.heappush(pq, (0, k))  # heapq implements min-heap

        while len(pq):
            _, u = heapq.heappop(pq)    # poll the edge with the least weight (time)
            for v, w in graph[u]:   # O(E)
                if dist[v - 1] > dist[u - 1] + w:
                    dist[v - 1] = dist[u - 1] + w
                    heapq.heappush(pq, (dist[v - 1], v))    # O(log(V))?

        ans = max(dist)  # O(V)
        return ans if ans != inf else -1


# @lc code=end

