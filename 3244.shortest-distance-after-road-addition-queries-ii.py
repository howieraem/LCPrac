class Solution(object):
    # No overlapping query paths, so just remove middle nodes covered by queries
    # T: O(n + len(queries))
    # S: O(n)
    def shortestDistanceAfterQueries(self, n, queries):
        """
        :type n: int
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        res = [0] * len(queries)
        to_furthest = {}
        for i in range(n - 1):
            to_furthest[i] = i + 1
        
        for i, (u, v) in enumerate(queries):
            if u not in to_furthest or to_furthest[u] >= v:
                res[i] = len(to_furthest)
                continue
            
            # remove intermediate nodes, and the distance is just the number of remaining nodes
            w = to_furthest[u]
            while w is not None and w < v:
                w = to_furthest.pop(w, None)
            to_furthest[u] = v
            res[i] = len(to_furthest)

        return res
