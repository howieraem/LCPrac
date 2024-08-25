from typing import List

class Solution:
    # T: O(n * k)
    # S: O(1)
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        for _ in range(k):
            min_x = float('inf')
            min_i = -1
            for i, x in enumerate(nums):
                if x < min_x:
                    min_x = x
                    min_i = i
            nums[min_i] *= multiplier
        return nums
