#
# @lc app=leetcode id=210 lang=python3
#
# [210] Course Schedule II
#
from collections import deque
from typing import *

# @lc code=start
class Solution:
    # T: O(V + E), V := numCourses, E := len(prerequisites)
    # S: O(V + E)
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # Build graph
        in_deg = [0] * numCourses
        graph = [[] for _ in range(numCourses)]
        for dst, src in prerequisites:
            graph[src].append(dst)
            in_deg[dst] += 1

        # Topological sort
        q = deque()
        for i in range(numCourses):
            if in_deg[i] == 0:
                q.append(i)
        
        res = [-1] * numCourses
        p = 0
        while len(q):
            qs = len(q)
            for _ in range(qs):
                pre = q.popleft()
                numCourses -= 1
                res[p] = pre
                p += 1

                for next_course in graph[pre]:
                    in_deg[next_course] -= 1
                    if in_deg[next_course] == 0:
                        q.append(next_course)

        # Cycle exists if the number of remaining courses is not 0
        return res if numCourses == 0 else []

# @lc code=end

