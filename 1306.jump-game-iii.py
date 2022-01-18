#
# @lc app=leetcode id=1306 lang=python3
#
# [1306] Jump Game III
#
from collections import deque
from typing import *

# @lc code=start
class Solution:
    # DFS
    # T: O(n)
    # S: O(n)
    def canReach(self, arr: List[int], start: int) -> bool:
        if start < 0 or start >= len(arr) or arr[start] < 0:
            return False
        arr[start] *= -1   # mark visited
        return arr[start] == 0 or \
            self.canReach(arr, start - arr[start]) or \
            self.canReach(arr, start + arr[start])

    # BFS
    # T: O(n)
    # S: O(n)
    def canReach(self, arr: List[int], start: int) -> bool:
        q = deque()
        q.append(start)
        while q:
            qs = len(q)
            for _ in range(qs):
                cur = q.popleft()
                if arr[cur] == 0:
                    return True
                elif arr[cur] < 0:
                    continue

                if cur + arr[cur] < len(arr):
                    q.append(cur + arr[cur])
                if cur - arr[cur] >= 0:
                    q.append(cur - arr[cur])

                arr[cur] *= -1
        return False

# @lc code=end

