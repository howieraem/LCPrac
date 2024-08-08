#
# @lc app=leetcode id=523 lang=python3
#
# [523] Continuous Subarray Sum
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(min(n, k))
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        running_sum_indices = dict()
        running_sum_indices[0] = -1  # IMPORTANT
        running_sum = 0

        # Math: (a + (n * k)) % k = a % k
        for i in range(len(nums)):
            running_sum = (running_sum + nums[i]) % k
            if running_sum not in running_sum_indices:
                running_sum_indices[running_sum] = i
            elif i - running_sum_indices[running_sum] > 1:  # subarray is not empty
                    return True
                
        return False

# @lc code=end

