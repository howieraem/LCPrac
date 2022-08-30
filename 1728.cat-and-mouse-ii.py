#
# @lc app=leetcode id=1728 lang=python3
#
# [1728] Cat and Mouse II
#
import functools
from typing import List, Tuple

# @lc code=start
class Solution:
    # T: O((m * n) ^ 3 * (m + n))
    # S: O((m * n) ^ 3)
    def canMouseWin(self, grid: List[str], catJump: int, mouseJump: int) -> bool:
        D = (1, 0, -1, 0, 1)
        m = len(grid)
        n = len(grid[0])

        mouse_pos = None
        cat_pos = None
        avail_cells = 0
        for i in range(m):
            for j in range(n):
                avail_cells += grid[i][j] != '#'
                if grid[i][j] == 'M':
                    mouse_pos = (i, j)
                elif grid[i][j] == 'C':
                    cat_pos = (i, j)

        # Estimated depth threshold. 1000 is too large and will cause TLE.
        max_turns = (avail_cells << 1)
        # More appropriate threshold should be avail_cells ^ 2, but might still be too large to pass some test cases.

        # Return True if mouse wins else False
        @functools.lru_cache(None)
        def dfs(turn: int, mouse_pos: Tuple[int], cat_pos: Tuple[int]) -> bool:
            if turn == max_turns:
                return False
            if turn & 1:
                # cat's turn
                i, j = cat_pos
                for d in range(4):
                    for jump in range(catJump + 1):  # cat can stay, jump = 0
                        ni = i + D[d] * jump
                        nj = j + D[d + 1] * jump
                        if 0 <= ni < m and 0 <= nj < n and grid[ni][nj] != '#':
                            next_cat_pos = (ni, nj)
                            if next_cat_pos == mouse_pos or grid[ni][nj] == 'F' or not dfs(turn + 1, mouse_pos, next_cat_pos):
                                # This condition will also handle the case that the cat cannot jump through the mouse
                                return False
                        else:
                            # cannot jump further in the current direction
                            break
                return True
            else:
                # mouse's turn
                i, j = mouse_pos
                for d in range(4):
                    # Optimization: Although mouse can stay, if cat also stays, mouse will still lose eventually.
                    # Thus, the minimum mouse jump is 1.
                    for jump in range(1, mouseJump + 1):
                        ni = i + D[d] * jump
                        nj = j + D[d + 1] * jump
                        if 0 <= ni < m and 0 <= nj < n and grid[ni][nj] != '#':
                            if grid[ni][nj] == 'F' or dfs(turn + 1, (ni, nj), cat_pos):
                                return True
                        else:
                            # cannot jump further in the current direction
                            break
                return False

        return dfs(0, mouse_pos, cat_pos)
            

# @lc code=end

