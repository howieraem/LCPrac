#
# @lc app=leetcode id=410 lang=python3
#
# [410] Split Array Largest Sum
#
from typing import List

# @lc code=start
class Solution:
    # Binary search: minimum possible subarr sum is max(nums), maximum possible subarr sum is sum(nums) (if all nums are nonnegative)
    # T: O(n * log(x)), n := len(nums), x := sum(nums) - max(nums)
    # S: O(1)
    def splitArray(self, nums: List[int], m: int) -> int:
        l = r = 0
        for x in nums:
            l = max(l, x)
            r += x
        if m == 1:  # trivial
            return r
        while l < r:
            mid = l + ((r - l) >> 1)
            n_splits = self.get_n_splits(nums, mid)
            if n_splits > m:
                l = mid + 1
            else:
                # find the leftmost (smallest) possible subarr sum 
                # when n_splits == m
                r = mid
        return l

    # T: O(n)
    @staticmethod
    def get_n_splits(nums: List[int], max_subarr_sum: int):
        n_splits = 1
        cur_sum = 0
        for x in nums:
            cur_sum += x
            if cur_sum > max_subarr_sum:
                n_splits += 1
                cur_sum = x
        return n_splits

# @lc code=end

