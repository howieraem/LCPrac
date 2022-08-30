#
# @lc app=leetcode id=2172 lang=python3
#
# [2172] Maximum AND Sum of Array
#
import functools
from typing import List

# @lc code=start
class Solution:
    # T: O(2 ^ numSlots * len(nums))
    # S: O(2 ^ numSlots)
    def maximumANDSum(self, nums: List[int], numSlots: int) -> int:
        memo = dict()

        # Use a bitmask to track number assignments to slots
        def dfs(i, mask):
            if i == len(nums):
                return 0
            if mask in memo:
                return memo[mask]

            ans = 0
            for j in range(numSlots):
                idx_in_all_slots = (j << 1)  # The index of the selected number in all slots (each slot has 2 numbers)
                if mask & (1 << idx_in_all_slots) == 0:
                    # The 1st spot of the current slot is available
                    ans = max(ans, (nums[i] & (j + 1)) + dfs(i + 1, mask ^ (1 << idx_in_all_slots)))
                elif mask & (1 << (idx_in_all_slots + 1)) == 0:
                    # The 2nd spot of the current slot is available
                    ans = max(ans, (nums[i] & (j + 1)) + dfs(i + 1, mask ^ (1 << (idx_in_all_slots + 1))))
            memo[mask] = ans
            return ans

        return dfs(0, 0)

# @lc code=end

