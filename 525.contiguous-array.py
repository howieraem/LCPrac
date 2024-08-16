#
# @lc app=leetcode id=525 lang=python3
#
# [525] Contiguous Array
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n)
    def findMaxLength(self, nums: List[int]) -> int:
        prefix_sum_idxs = {
            0: -1  # handle edge case like if the subarray begins from index 0
        }

        prefix_sum = 0
        ans = 0

        for i in range(len(nums)):
            # The target subarray sum should equals 0
            prefix_sum += 1 if nums[i] == 1 else -1

            last_idx = prefix_sum_idxs.get(prefix_sum, None)
            if last_idx is not None:
                ans = max(ans, i - last_idx)
            else:
                prefix_sum_idxs[prefix_sum] = i

        return ans

# @lc code=end

