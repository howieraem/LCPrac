#
# @lc app=leetcode id=1340 lang=python3
#
# [1340] Jump Game V
#
from typing import List

# @lc code=start
class Solution:
    # Mono-stack + DP
    # T: O(n)
    # S: O(n)
    def maxJumps(self, arr: List[int], d: int) -> int:
        n = len(arr)
        dp = [1] * (n + 1)
        stack = []
        for i, a in enumerate(arr + [float('inf')]):
            while stack and arr[stack[-1]] < a:
                l = [stack.pop()]
                while stack and arr[stack[-1]] == arr[l[0]]:
                    l.append(stack.pop())   # append indices of equal arr values
                for j in l:
                    if i - j <= d:  # d is the maximum span of one jump
                        dp[i] = max(dp[i], dp[j] + 1)
                    if stack and j - stack[-1] <= d:
                        dp[stack[-1]] = max(dp[stack[-1]], dp[j] + 1)
            stack.append(i)
        ans = 0
        for i in range(n):
            ans = max(ans, dp[i])
        return ans

        
# @lc code=end

