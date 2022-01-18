#
# @lc app=leetcode id=1345 lang=python3
#
# [1345] Jump Game IV
#
from collections import defaultdict, deque
from typing import *

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n)
    def minJumps(self, arr: List[int]) -> int:
        val2idxs = defaultdict(list)
        for i, x in enumerate(arr):
            val2idxs[x].append(i)

        n = len(arr)
        vis = [False] * n
        vis[0] = True
        q = deque()
        q.append(0)
        val_vis = set()

        steps = 0
        while q:
            qs = len(q)
            for _ in range(qs):
                i = q.popleft()
                if i == n - 1:
                    return steps
                for j in (i - 1, i + 1):
                    if 0 <= j < n and not vis[j]:
                        vis[j] = True
                        q.append(j)
                
                # Very important pruning!
                # Avoids visiting indices of the same value more than once.
                if arr[i] not in val_vis:
                    for j in val2idxs[arr[i]]:
                        if not vis[j]:  # 0 <= j < n is always true
                            vis[j] = True
                            q.append(j)
                    val_vis.add(arr[i])
            steps += 1
        return 0


# @lc code=end

