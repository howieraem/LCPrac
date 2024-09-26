from collections import defaultdict
from typing import List

class Solution:
    # T: O(n)
    # S: O(n)
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        freqs = defaultdict(int)
        n = len(nums)

        ans = 0

        # sliding window
        l = 0
        for r in range(n):
            freqs[nums[r]] += 1
            while freqs[nums[r]] > k:
                freqs[nums[l]] -= 1
                l += 1

            ans = max(ans, r - l + 1)

        return ans
