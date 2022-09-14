#
# @lc app=leetcode id=1885 lang=python3
#
# [1885] Count Pairs in Two Arrays
#
from typing import *

# @lc code=start
class Solution:
    # T: O(n * log(n)), n := len(nums1) + len(nums2)
    # S: O(n)
    def countPairs(self, nums1: List[int], nums2: List[int]) -> int:
        # nums1[i] + nums1[j] > nums2[i] + nums2[j] <=> (nums1[i] - nums2[i]) + (nums1[j] - nums2[j]) > 0
        # Given diffs = [nums1[0]-nums2[0], nums1[1]-nums2[1], ...], this problem can be rewritten as:
        # Find the number of (i, j) pairs such that i < j and diffs[i] + diffs[j] > 0.
        diffs = [n1 - n2 for n1, n2 in zip(nums1, nums2)]
        diffs.sort()

        ans = 0
        l = 0
        r = len(diffs) - 1
        while l < r:
            if diffs[l] + diffs[r] > 0:
                ans += (r - l)
                r -= 1
            else:
                l += 1
        return ans

# @lc code=end

