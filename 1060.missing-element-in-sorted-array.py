#
# @lc app=leetcode id=1060 lang=python3
#
# [1060] Missing Element in Sorted Array
#
from typing import List

# @lc code=start
class Solution:
    # Binary search
    # T: O(log(n))
    # S: O(1)
    def missingElement(self, nums: List[int], k: int) -> int:
        n = len(nums)
        if n == 0:
            return k
        
        # Formula: given j > i, n_missing between nums[i] and nums[j] is 
        # (nums[j] - nums[i]) - (j - i)
        n_missing = (nums[-1] - nums[0]) - (n - 1 - 0)
        if n_missing < k:
            # There are less missing slots between nums[0] and nums[-1].
            # The target number will be greater than nums[-1].
            return nums[-1] + (k - n_missing)
        
        l = 0
        r = n - 1
        n_missing = 0

        while l <= r:
            m = l + ((r - l) >> 1)
            n_missing = (nums[m] - nums[0]) - (m - 0)

            if n_missing < k:
                l = m + 1
            else:
                r = m - 1
        
        if n_missing >= k:
            # The target is to the left of nums[l] (excl.)
            return nums[l] - 1 + (k - n_missing)
        
        return nums[r] + (k - n_missing)

    """
    Follow-up: now suppose the minimum missing number is 1.
    Examples: 
    - input nums = [2, 14, 16, 17], k = 4 -> output: 5
    - input nums = [8, 9], k = 1 -> output: 1
    """
    @staticmethod
    def n_missing_above_zero(nums: List[int], idx: int) -> int:
        return (nums[idx] - 1) - (idx - 0) if 0 <= idx < len(nums) else 0
    
    def missingElementWithMin(self, nums: List[int], k: int) -> int:
        n = len(nums)
        if n == 0:
            return k
        
        # Formula: given j > i, n_missing between nums[i] and nums[j] is 
        # (nums[j] - nums[i]) - (j - i)
        n_missing = self.n_missing_above_zero(nums, n - 1)
        if n_missing < k:
            # There are less missing slots between nums[0] and nums[-1].
            # The target number will be greater than nums[-1].
            return nums[-1] + (k - n_missing)
        
        l = 0
        r = n - 1
        n_missing = 0

        while l < r:
            m = l + ((r - l) >> 1)
            n_missing = self.n_missing_above_zero(nums, m)

            if n_missing < k:
                l = m + 1
            else:
                r = m

        return nums[l - 1] + k - self.n_missing_above_zero(nums, l - 1)

# @lc code=end

