#
# @lc app=leetcode id=992 lang=python3
#
# [992] Subarrays with K Different Integers
#
from typing import List

# @lc code=start
class Solution:
    # Sliding window
    # T: O(n)
    # S: O(n)
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        # It is hard to get the number of windows with an exact no. of distinct numbers = k.
        # Instead, we find the number of windows with no. of distinct numbers less than or 
        # equal to k and (k - 1) respectively, and get the final answer from their difference.
        return self.nSubarraysWithAtMostKDistinct(nums, k) - \
                self.nSubarraysWithAtMostKDistinct(nums, k - 1)

    def nSubarraysWithAtMostKDistinct(self, nums: List[int], k: int) -> int:
        freqs = dict()
        ans = 0
        window_distinct_cnt = 0
        l = 0
        for r in range(len(nums)):
            r_freq = freqs.get(nums[r], 0) + 1
            window_distinct_cnt += (r_freq == 1)
            freqs[nums[r]] = r_freq

            while window_distinct_cnt > k:
                l_freq = freqs[nums[l]] - 1
                window_distinct_cnt -= (l_freq == 0)
                freqs[nums[l]] = l_freq
                l += 1

            ans += r - l + 1  # no. of subarr with no. of distinct numbers at most k
        
        return ans

# @lc code=end

