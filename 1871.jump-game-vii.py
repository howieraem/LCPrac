#
# @lc app=leetcode id=1871 lang=python3
#
# [1871] Jump Game VII
#
from collections import deque

# @lc code=start
class Solution:
    # DP + sliding window
    # T: O(n)
    # S: O(n)
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        n = len(s)
        pre = 0
        dp = [False] * n   # dp[i] = True if s[i] can be reached
        dp[0] = True

        '''
        1. To determine the state of dp[i], one need to check the states in window dp[i - maxJ : i - minJ], 
           because any one of them can reach i if it's labeled True.
        2. Then you need to check if there is a True in this window. Notice that this is a sliding window problem, 
           so you don't need to calculate it everytime. You only need to remove the effect from dp[i - maxJ - 1] 
           and add the dp[i - minJ]. This is done by these two lines of code pre += dp[i - minJ] and pre -= dp[i - maxJ - 1]
        3. The if statements `if i >= minJ:` and `if i > maxJ:` are dealing with the initial boundary.
        '''
        for i in range(1, n):
            if i >= minJump and dp[i - minJump]:
                pre += 1
            if i > maxJump and dp[i - maxJump - 1]:
                pre -= 1
            dp[i] = pre > 0 and s[i] == '0'
        return dp[n - 1]

    # BFS (+ Greedy?)
    # T: O(n)
    # S: O(n)
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        q = deque()
        q.append(0)
        furthest = 0
        while q:
            cur = q.popleft()
            if cur == len(s) - 1:
                return True
            start = max(cur + minJump, furthest)
            for i in range(start, min(cur + maxJump + 1, len(s))):
                if s[i] == '0':
                    q.append(i)
            furthest = cur + maxJump
        return False

# @lc code=end

