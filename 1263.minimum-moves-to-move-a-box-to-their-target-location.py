#
# @lc app=leetcode id=1263 lang=python3
#
# [1263] Minimum Moves to Move a Box to Their Target Location
#
from collections import deque
from typing import List, Tuple

# @lc code=start
class Solution:
    # Nested BFS
    # T: O((m * n) ^ 2)
    # S: O((m * n) ^ 2)
    def minPushBox(self, grid: List[List[str]]) -> int:
        D = (0, 1, 0, -1, 0)
        m = len(grid)
        n = len(grid[0])
        
        box = person = target = None
        found_mask = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 'B':
                    box = (i, j)
                    found_mask |= 1
                elif grid[i][j] == 'S':
                    person = (i, j)
                    found_mask |= (1 << 1)
                elif grid[i][j] == 'T':
                    target = (i, j)
                    found_mask |= (1 << 2)
                
                if found_mask == 7:
                    # 3 required positions all found
                    break
            else:
                # inner loop didn't break
                continue
            break  # 3 required positions all found

        def is_valid(pos: Tuple[int, int]) -> bool:
            return 0 <= pos[0] < m and 0 <= pos[1] < n and grid[pos[0]][pos[1]] != '#'

        # Check if the person can go from src to dst
        def is_reachable(src: Tuple[int, int], dst: Tuple[int, int], box: Tuple[int, int]) -> bool:
            q = deque()
            vis = set()
            q.append(src)
            vis.add(src)
            while len(q):
                cur = q.popleft()
                if cur == dst:
                    return True
                
                for d in range(4):
                    new_pos = (cur[0] + D[d], cur[1] + D[d + 1])
                    if is_valid(new_pos) and new_pos not in vis and new_pos != box:
                        q.append(new_pos)
                        vis.add(new_pos)
            return False

        q = deque()
        vis = set()
        init_state = (box, person)
        q.append(init_state)
        vis.add(init_state)

        steps = 0
        while len(q):
            qs = len(q)
            for _ in range(qs):
                box, person = q.popleft()
                if box == target:
                    return steps
                
                for d in range(4):
                    new_box = (box[0] + D[d], box[1] + D[d + 1])  # position of the box after the person pushes
                    new_person = (box[0] - D[d], box[1] - D[d + 1])  # position where the person pushes the box
                    if is_valid(new_box) and is_valid(new_person):
                        new_state = (new_box, new_person)
                        if new_state not in vis and is_reachable(person, new_person, box):
                            q.append(new_state)
                            vis.add(new_state)
            steps += 1
        return -1

        
# @lc code=end

