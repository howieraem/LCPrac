#
# @lc app=leetcode id=805 lang=python3
#
# [805] Split Array With Same Average
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n ^ 3)
    # S: O(n ^ 2)?
    def splitArraySameAverage(self, nums: List[int]) -> bool:
        # sum(nums) / n = sum(a) / len(a) = sum(b) / (n - len(a))
        # 1 <= len(a) <= n / 2
        # sum(a) = sum(nums) * len(a) / n has to be an integer,
        # so sum(nums) * len(a) % n = 0. 
        n = len(nums)
        m = n >> 1
        s = sum(nums)

        # Early pruning
        possible = False
        for j in range(1, m + 1):
            if s * j % n == 0:
                possible = True
                break
        if not possible:
            return False

        # Similar ideas to Q416
        # Generate all possible combination sum of len(a) numbers from nums,
        # then for each valid len(a), check if sum(nums) * len(a) / n exists in 
        # the len(a)-th combination sum hash set
        # dp[i][j] is all possible combination sum of j numbers from subarray nums[0...i]
        # dp[i+1][j] = dp[i][j] UNION {s + nums[i+1] for s in dp[i][j-1]}
        # After state compression
        # dp[j] = dp[j] UNION {s + nums[i+1] for s in dp[j-1]}
        dp = [set() for _ in range(m + 1)]
        dp[0].add(0)
        for x in nums:
            for j in range(m, 0, -1):  # reversed due to state compression
                for sa in dp[j - 1]:
                    dp[j].add(sa + x)
        
        for j in range(1, m + 1):
            if s * j % n == 0 and s * j // n in dp[j]:
                return True
        return False

# @lc code=end

