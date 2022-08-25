#
# @lc app=leetcode id=1284 lang=python3
#
# [1284] Minimum Number of Flips to Convert Binary Matrix to Zero Matrix
#
from collections import deque
from typing import *

# @lc code=start
class Solution:
    # T: O((m * n) * 2 ^ (m * n))
    # S: O(2 ^ (m * n))
    def minFlips(self, mat: List[List[int]]) -> int:
        M = len(mat)
        N = len(mat[0])
        D = (0, 0, 1, 0, -1, 0)

        # Represent the binary mat as a mask instead
        mask = 0
        for i in range(M):
            for j in range(N):
                mask |= (mat[i][j] << (i * N + j))

        q = deque()
        vis = set()
        q.append(mask)
        vis.add(mask)
        steps = 0
        while len(q):
            qs = len(q)
            for _ in range(qs):
                cur_mask = q.popleft()
                if cur_mask == 0:
                    return steps

                # Flip each cell and its neighbors
                for i in range(M):
                    for j in range(N):
                        next_mask = cur_mask
                        for d in range(5):
                            r = i + D[d]
                            c = j + D[d + 1]
                            if 0 <= r < M and 0 <= c < N:
                                next_mask ^= (1 << (r * N + c))
                        if next_mask not in vis:
                            q.append(next_mask)
                            vis.add(next_mask)
            steps += 1

        return -1

# @lc code=end

