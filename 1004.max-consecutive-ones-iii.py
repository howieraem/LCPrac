#
# @lc app=leetcode id=1004 lang=python3
#
# [1004] Max Consecutive Ones III
#
from typing import List

# @lc code=start
class Solution:
    # Sliding window
    # T: O(n)
    # S: O(1)
    def longestOnes(self, nums: List[int], k: int) -> int:
        l = r = 0
        for r in range(len(nums)):
            # Try extending the window to the right,
            # and update the number of zeros.
            if not nums[r]:
                k -= 1

            if k < 0:
                # More than k zeros inside the window.
                # Try shifting the left boundary to
                # reduce the number of zeros.
                if not nums[l]:
                    k += 1
                l += 1
        return r - l + 1

# @lc code=end

