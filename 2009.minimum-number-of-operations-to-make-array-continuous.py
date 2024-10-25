#
# @lc app=leetcode id=2009 lang=python3
#
# [2009] Minimum Number of Operations to Make Array Continuous
#
from typing import List

# @lc code=start
class Solution:
    # sorting + sliding window
    # T: O(n * log(n))
    # S: O(n) timsort
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        uniq_nums = sorted(set(nums))
        n_uniq = len(uniq_nums)

        ans = n
        l = 0
        for r in range(n_uniq):
            while l <= r and uniq_nums[l] + n <= uniq_nums[r]:
                l += 1

            # Length of window is r - l + 1, so need to replace n - (r - l + 1)
            # elements to make the original nums continuous (no. of duplicates
            # in the original nums is implicitly included here).
            ans = min(ans, n - (r - l + 1))  

        return ans

# @lc code=end

