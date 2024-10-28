#
# @lc app=leetcode id=1856 lang=python3
#
# [1856] Maximum Subarray Min-Product
#
from typing import *

# @lc code=start
class Solution:
    # Prefix sum and mono-stack
    # similar to Q2281
    # T: O(n)
    # S: O(n)
    def maxSumMinProduct(self, nums: List[int]) -> int:
        MOD = 10 ** 9 + 7
        n = len(nums)

        # Mono-stack for finding subarray minima
        # find next smaller to the right
        nxt_small_r = [n - 1] * n
        stack = []
        for i in range(n):
            while len(stack) > 0 and nums[stack[-1]] > nums[i]:
                nxt_small_r[stack.pop()] = i - 1
            stack.append(i)

        # find next smaller to the left
        nxt_small_l = [0] * n
        stack = []
        for i in range(n - 1, -1, -1):
            while len(stack) > 0 and nums[stack[-1]] > nums[i]:
                nxt_small_l[stack.pop()] = i + 1
            stack.append(i)

        pre_sum = [0] * (n + 1)
        for i in range(n):
            pre_sum[i + 1] = pre_sum[i] + nums[i]

        ans = float('-inf')
        # Check maximum min-product for subarrs with nums[i] as the minimum
        for i in range(n):
            subarr_sum = pre_sum[nxt_small_r[i] + 1] - pre_sum[nxt_small_l[i]]
            ans = max(ans, nums[i] * subarr_sum)
        return ans % MOD

# @lc code=end

