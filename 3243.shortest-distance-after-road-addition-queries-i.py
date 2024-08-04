from collections import defaultdict, deque

class Solution(object):
    # Dijkstra
    # T: O(n * len(queries))
    # S: O(n)
    def shortestDistanceAfterQueries(self, n, queries):
        """
        :type n: int
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        graph = defaultdict(list)
        for i in range(n - 1):
            graph[i].append(i + 1)

        res = []

        for query in queries:
            graph[query[0]].append(query[1])
            res.append(self.bfs(graph, n - 1))
        return res

    def bfs(self, graph, n):
        q = deque()
        dists = [-1] * n
        q.append(0)
        d = 0
        while q:
            qs = len(q)
            d += 1
            for _ in range(qs):
                x = q.popleft()

                for neighbor in graph[x]:
                    if neighbor == n:
                        return d
                    if dists[neighbor] == -1 or d < dists[neighbor]:
                        dists[neighbor] = d
                        q.append(neighbor)
        return d
