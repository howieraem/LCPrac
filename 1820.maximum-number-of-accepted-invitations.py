#
# @lc app=leetcode id=1820 lang=python3
#
# [1820] Maximum Number of Accepted Invitations
#
from typing import *

# @lc code=start
class Solution:
    # Hungarian Algorithm
    # T: O(m * n)
    # S: O(n)
    def maximumInvitations(self, grid: List[List[int]]) -> int:
        m = len(grid)  # the number of boys
        n = len(grid[0])  # the number of girls
        girl_matches = [-1] * n  # girl_matches[girl] means the matched boy of girl

        def dfs(boy: int, boy_visited: List[bool]) -> bool:
            for girl in range(n):
                # 1. Can take a girl if you haven't asked her before already.
                # 2. If you wish to take a girl that's been taken, she'll only go with you 
                #    if her current partner finds a new girl (i.e., the girl's mate can be
                #    changed to someone else).
                if grid[boy][girl] and not boy_visited[girl]:
                    boy_visited[girl] = True
                    if girl_matches[girl] == -1 or dfs(girl_matches[girl], boy_visited):
                        girl_matches[girl] = boy
                        return True

            return False

        ans = 0
        for boy in range(m):
            ans += dfs(boy, [False] * n)
        return ans

        
# @lc code=end

