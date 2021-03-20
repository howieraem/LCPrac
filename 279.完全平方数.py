#
# @lc app=leetcode.cn id=279 lang=python3
#
# [279] 完全平方数
#
from collections import deque

# @lc code=start
class Solution:
    def numSquares(self, n: int) -> int:
        """Dynamic programming approach"""
        square_nums = [i**2 for i in range(0, int(n**0.5)+1)]
        
        # numSquares(n) = min(numSquares(n-k) - 1 for k in squareNumbers)
        dp = [float('inf')] * (n+1)
        dp[0] = 0   # bottom case
        
        for i in range(1, n+1):
            for square in square_nums:
                if i < square:
                    break
                dp[i] = min(dp[i], dp[i-square] + 1)
        
        return dp[-1]

    
    def numSquares(self, n: int) -> int:
        """BFS approach, much faster than DP in python3.
        Recall that BFS can give the shortest path because
        it performs level traversal in the search tree."""
        if not n: 
            return 0
        queue = deque([n])
        step = 0
        visited = set()
        while queue:
            step += 1
            l = len(queue)
            for _ in range(l):
                tmp = queue.pop()
                for i in range(1, int(tmp**0.5)+1):     # square numbers for `tmp`
                    x = tmp - i**2
                    if not x:
                        return step
                    if x not in visited:
                        queue.appendleft(x)
                        visited.add(x)
        return step


# @lc code=end

