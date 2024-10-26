from typing import List

class Solution:
    # Binary search the min diff such that the number of pairs is less than p
    # T: O(n * (log(n) + log(max(nums) - min(nums))))
    # S: O(n) timsort
    def minimizeMax(self, nums: List[int], p: int) -> int:
        N = len(nums)
        if N == 0:
            return 0

        nums.sort()

        # range for binary search
        l = 0                        # min possible diff is non-negative
        r = nums[-1] - nums[0]       # max possible diff is max(nums) - min(nums)

        while l < r:
            m = l + ((r - l) >> 1)   # candidate diff

            n_pairs_diff_at_most_m = 0
            i = 1
            while i < N and n_pairs_diff_at_most_m < p:
                is_diff_at_most_m = (nums[i] - nums[i - 1] <= m)
                i += is_diff_at_most_m  # pairs can't overlap
                n_pairs_diff_at_most_m += is_diff_at_most_m
                i += 1

            if n_pairs_diff_at_most_m >= p:
                r = m
            else:
                l = m + 1

        return l   # find left most diff (as small as possible)
