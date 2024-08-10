from typing import List


class Solution:
    # T: O(n)
    # S: O(1)
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        ans = 0
        cur_zero_subarrays = 0

        for num in nums:
            if num == 0:
                cur_zero_subarrays += 1
                ans += cur_zero_subarrays
            else:
                cur_zero_subarrays = 0

        return ans
