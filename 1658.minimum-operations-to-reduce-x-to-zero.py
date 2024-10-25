#
# @lc app=leetcode id=1658 lang=python3
#
# [1658] Minimum Operations to Reduce X to Zero
#
from typing import List

# @lc code=start
class Solution:
    # Sliding window
    # T: O(n)
    # S: O(1)
    def minOperations(self, nums: List[int], x: int) -> int:
        tot = sum(nums)

        # Find the longest window in the middle of the array with sum less than 
        # total sum minus x. The final answer will just be the array length minus 
        # this window's length (if valid).
        window_sum = 0
        max_valid_window_sz = -1
        l = 0
        for r in range(len(nums)):
            window_sum += nums[r]
            
            while l <= r and window_sum > tot - x:
                window_sum -= nums[l]
                l += 1
            
            if window_sum == tot - x:
                max_valid_window_sz = max(max_valid_window_sz, r - l + 1)
        
        return len(nums) - max_valid_window_sz if max_valid_window_sz != -1 else -1


# @lc code=end

