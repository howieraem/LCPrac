from typing import *


def solve(nums: List[int]) -> int:
    """Returns the minimum difference between any 2 non-empty subsets of nums"""
    n = len(nums)
    if n == 0:
        return 0
    
    s = sum(nums)
    # dp[i][j] means whether a subset in nums[1...i] sums up to j
    dp = [[False] * (s + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        dp[i][0] = True

    for i in range(1, n + 1):
        for j in range(1, s + 1):
            if j < nums[i - 1]:
                dp[i][j] = dp[i - 1][j]
            else:
                dp[i][j] = dp[i - 1][j - nums[i - 1]]

    # To minimize diff, a subset's sum should be as close to s//2 as possible
    for j in range(s >> 1, -1, -1):
        if dp[n][j]:
            return s - (j << 1)
    return -1
