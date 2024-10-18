from typing import *


def solve(nums: List[int], k: int) -> int:
    """
    Returns no. of subseqs of nums with sum equal to k.
    
    Constraint: nums[i] >= 0
    """
    n = len(nums)
    if n == 0:
        return 0
    
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    dp[0][0] = 1

    for i in range(1, n + 1):
        for j in range(1, k + 1):
            if j < nums[i - 1]:
                dp[i][j] = dp[i - 1][j]
            else:
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]]
    
    return dp[n][k]
