#
# @lc app=leetcode id=499 lang=python3
#
# [499] The Maze III
#
import heapq
from typing import List

# @lc code=start
class Solution:
    # T: O(m * n * log(m * n))
    # S: O(m * n)
    def findShortestWay(self, maze: List[List[int]], ball: List[int], hole: List[int]) -> str:
        m = len(maze)
        n = len(maze[0])
        D = ((1, 0, 'd'), (0, -1, 'l'), (0, 1, 'r'), (-1, 0, 'u'))

        # Priority queue of tuples ([dist, path], ball_pos)
        init_dist_and_path = (0, "")
        min_heap = [(init_dist_and_path, ball)]
        # Compare dist and then path lexicographically
        best_dists_and_paths = [[(float('inf'), "") for _ in range(n)] for _ in range(m)]  # can be used to check visited
        best_dists_and_paths[ball[0]][ball[1]] = init_dist_and_path

        while len(min_heap):
            (dist, path), pos = heapq.heappop(min_heap)
            if pos == hole:
                return path
            for dr, dc, dirn in D:
                n_pos = pos[:]
                d_dist = 0
                # ball will keep moving until hitting a wall or reaching the hole
                while 0 <= n_pos[0] + dr < m and 0 <= n_pos[1] + dc < n and maze[n_pos[0] + dr][n_pos[1] + dc] != 1:
                    n_pos[0] += dr
                    n_pos[1] += dc
                    d_dist += 1
                    if n_pos == hole:
                        break
                new_dist_and_path = (dist + d_dist, path + dirn)
                if best_dists_and_paths[n_pos[0]][n_pos[1]] > new_dist_and_path:
                    best_dists_and_paths[n_pos[0]][n_pos[1]] = new_dist_and_path
                    heapq.heappush(min_heap, (new_dist_and_path, n_pos))
        return "impossible"

# @lc code=end

