#
# @lc app=leetcode id=1498 lang=python3
#
# [1498] Number of Subsequences That Satisfy the Given Sum Condition
#
from typing import *

# @lc code=start
class Solution:
    # T: O(n * log(n))
    # S: O(n) for timsort
    def numSubseq(self, nums: List[int], target: int) -> int:
        MOD = pow(10, 9) + 7
        nums.sort()
        l, r = 0, len(nums) - 1
        ans = 0
        while l <= r:
            if nums[l] + nums[r] > target:
                r -= 1
            else:
                ans += pow(2, r - l, MOD) 
                l += 1
        # (a + b) % mod = (a % mod + b % mod) % mod
        # (a * b) % mod = ((a % mod) * (b % mod)) % mod
        return ans % MOD

# @lc code=end

