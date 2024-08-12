#
# @lc app=leetcode id=1685 lang=python3
#
# [1685] Sum of Absolute Differences in a Sorted Array
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        # `nums` is ascending, so:
        # res[i] = (nums[i] - nums[0]) + (nums[i] - nums[1]) + ... + (nums[i] - nums[i - 1]) + 
        #     (nums[i + 1] - nums[i]) + (nums[i + 2] - nums[i]) + ... + (nums[n - 1] - nums[i])
        # Rearrange:
        # res[i] = i * nums[i] - (nums[0] + ... + nums[i - 1]) + 
        #     (nums[i + 1] + ... + nums[n - 1]) - (n - i) * nums[i]
        # res[i] = i * nums[i] - prefix_sum[i] + suffix_sum[n - i] - (n - i) * nums[i]
        N = len(nums)
        res = [-1] * N

        # Compute in a rolling basis to save space,
        # because we don't need to compute difference between every pair of prefix sums
        prefix_sum = 0
        suffix_sum = sum(nums)

        for i, x in enumerate(nums):
            res[i] = (i * x - prefix_sum + suffix_sum - (N - i) * x)
            prefix_sum += x
            suffix_sum -= x

        return res

# @lc code=end

