from typing import *

class Solution:
    # Prefix sum
    # T: O(n ^ 2) worst
    # S: O(n)
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        n = len(nums)
        if n == 0:
            return 0
        
        pre_sum = [0] * (n + 1)
        for i in range(n):
            pre_sum[i + 1] = pre_sum[i] + nums[i]
        
        ans = float('inf')
        for length in range(l, r + 1):
            for i in range(n + 1 - length):
                subarr_sum = pre_sum[i + length] - pre_sum[i]
                if subarr_sum > 0:
                    ans = min(ans, subarr_sum)

        return ans if ans != float('inf') else -1
