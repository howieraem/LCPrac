from typing import *


def solve(nums: List[int], k: int) -> List[int]:
    """
    Returns a subseq of nums with sum equal to k.
    
    Constraint: nums[i] >= 1
    """
    n = len(nums)
    if n == 0:
        return []
    
    dp = [[False] * (k + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        dp[i][0] = True

    for i in range(1, n + 1):
        for j in range(1, k + 1):
            if j < nums[i - 1]:
                dp[i][j] = dp[i - 1][j]
            else:
                dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]]

    if not dp[n][k]:
        return []
    
    res = []
    i = n
    j = k
    while i > 0 and j > 0:
        if i > 0 and dp[i][j] != dp[i - 1][j]:
            res.append(nums[i - 1])
            j -= nums[i - 1]
        i -= 1
    
    res.reverse() # if the original subseq order is required
    return res


if __name__ == '__main__':
    res = solve([12, 1, 61, 5, 9, 2], 24)
    print(res)
