#
# @lc app=leetcode id=1838 lang=python3
#
# [1838] Frequency of the Most Frequent Element
#
from typing import List

# @lc code=start
class Solution:
    # Sliding window
    # T: O(n * log(n))
    # S: O(n) timsort
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        
        window_sum = 0
        ans = 0
        l = 0
        for r in range(len(nums)):
            window_sum += nums[r]

            # Goal: maximize the length of a window such that within k ops 
            # all numbers in this window become nums[r] (and nums[r] is the
            # most frequent number)
            while (r - l + 1) * nums[r] - window_sum > k:
                window_sum -= nums[l]
                l += 1

            ans = max(ans, r - l + 1)

        return ans

# @lc code=end

