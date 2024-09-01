from typing import List

class Solution:
    # T: O(n ^ 2)
    # S: O(n ^ 2)
    def maximumSubarrayXor(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        n = len(nums)
        dp = [[0] * n for _ in range(n)]
        for i in range(n):
            dp[i][i] = nums[i]

        # precompute XOR scores for all subarries
        for length in range(2, n + 1):
            for l in range(n - length + 1):
                r = l + length - 1
                dp[l][r] = dp[l][r - 1] ^ dp[l + 1][r]

        # then precompute max scores for all subarries
        for length in range(2, n + 1):
            for l in range(n - length + 1):
                r = l + length - 1
                dp[l][r] = max(dp[l][r], dp[l][r - 1], dp[l + 1][r])

        res = [0] * len(queries)
        for i, (l, r) in enumerate(queries):
            res[i] = dp[l][r]

        return res
