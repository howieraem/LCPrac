from typing import *

class Solution:
    # two pointers + array
    # T: O(n)
    # S: O(1)
    def isMonotonic(self, nums: List[int]) -> bool:
        n = len(nums)
        
        asc = True
        desc = True
        for i in range(1, n):
            asc &= (nums[i] >= nums[i - 1])
            desc &= (nums[i] <= nums[i - 1])
            if not (asc or desc):
                return False

        return asc or desc
