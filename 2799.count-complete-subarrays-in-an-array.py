from collections import defaultdict
from typing import List

class Solution:
    # T: O(n)
    # S: O(n)
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        k = len(set(nums))
        ans = 0
        l = 0
        windowed_freq = defaultdict(int)
        for r in range(n):
            windowed_freq[nums[r]] += 1

            # shrink window by moving left pointer
            while len(windowed_freq) == k:
                windowed_freq[nums[l]] -= 1
                if windowed_freq[nums[l]] == 0:
                    del windowed_freq[nums[l]]
                l += 1

            ans += l  # IMPORTANT

        return ans
