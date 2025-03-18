from typing import List

class Solution:
    # binary search + greedy + mini-max
    # T: O(n * log(n))
    # S: O(1)
    def minCapability(self, nums: List[int], k: int) -> int:
        n = len(nums)
        if n == 0:
            return 0

        # Minimum no. of houses robbed is one, so
        # l = min(nums), r = max(nums)
        l = float('inf')
        r = float('-inf')
        for x in nums:
            l = min(l, x)
            r = max(r, x)

        def can_rob(thres):
            robbed = 0
            i = 0
            while i < n:
                if nums[i] <= thres:
                    robbed += 1
                    i += 1  # can't rob adjacent house
                i += 1
            return robbed >= k  # at least k houses robbed

        # binary search left most
        while l < r:
            m = l + ((r - l) >> 1)
            if can_rob(m):
                r = m
            else:
                l = m + 1
        
        return l

