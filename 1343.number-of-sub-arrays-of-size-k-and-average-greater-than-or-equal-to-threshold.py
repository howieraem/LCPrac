#
# @lc app=leetcode id=1343 lang=python3
#
# [1343] Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        threshold *= k   # convert to avoid float precision issues
        window_sum = 0
        ans = 0
        for r in range(len(arr)):
            window_sum += arr[r]

            # First window
            if r == k - 1 and window_sum >= threshold:
                ans += 1

            if r >= k:
                l = r - k
                window_sum -= arr[l]
                ans += (window_sum >= threshold)
        return ans

# @lc code=end

