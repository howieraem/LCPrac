from typing import List

UNGUARDED = 0
GUARDED = 1
GUARD = 2
WALL = 3

class Solution:
    # Simulation + matrix
    # T: O(4 * m * n) = O(m * n)
    # S: O(m * n)
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        states = [[0] * n for _ in range(m)]

        # Trick: place walls and guards first
        for r, c in walls:
            states[r][c] = WALL
        for r, c in guards:
            states[r][c] = GUARD

        # For each guard, simulate what cells are guarded
        for r, c in guards:
            # keep travel in 4 directions,
            # and stop early if guard/wall
            # encountered
            
            # Up
            for nr in range(r - 1, -1, -1):
                if states[nr][c] == GUARD or states[nr][c] == WALL:
                    break
                states[nr][c] = GUARDED

            # Down
            for nr in range(r + 1, m):
                if states[nr][c] == GUARD or states[nr][c] == WALL:
                    break
                states[nr][c] = GUARDED

            # Left
            for nc in range(c - 1, -1, -1):
                if states[r][nc] == GUARD or states[r][nc] == WALL:
                    break
                states[r][nc] = GUARDED

            # Right
            for nc in range(c + 1, n):
                if states[r][nc] == GUARD or states[r][nc] == WALL:
                    break
                states[r][nc] = GUARDED

        # Count unguarded cells
        ans = 0
        for i in range(m):
            for j in range(n):
                ans += states[i][j] == UNGUARDED
        return ans
    
    # Alternative solution: if m and n are extremely large, 
    # and guards and walls are sparse (much less than m and n), 
    # binary search is faster.
