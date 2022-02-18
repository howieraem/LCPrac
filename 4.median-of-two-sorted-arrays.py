#
# @lc app=leetcode id=4 lang=python3
#
# [4] Median of Two Sorted Arrays
#
from cmath import inf
from typing import *

# @lc code=start
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            # Make nums2 the longer array
            nums2, nums1 = nums1, nums2

        n1, n2 = len(nums1), len(nums2)

        # Need to find indexes m1 and m2 from nums1 and nums2 respectively to
        # calculate the median of the merged array.
        # If (n1 + n2) & 1:
        #   median = max(nums1[m1 - 1], nums2[m2 - 1])
        # Else:
        #   median = (max(nums1[m1 - 1], nums2[m2 - 1]) + min(nums1[m1], num2[m2])) / 2.

        # Relationship of m1, m2 and array lengths:
        #   m1 + m2 = n1 + n2 - m1 - m2 + ((n1 + n2) & 1)
        #   m1 + m2 = (n1 + n2 + 1) // 2
        k = (n1 + n2 + 1) >> 1

        # Find m1 (lower bound) via binary search in nums1
        l, r = 0, n1
        while l < r:
            m1 = (l + r) >> 1
            m2 = k - m1
            if nums1[m1] >= nums2[m2 - 1]:
                r = m1
            else:
                l = m1 + 1

        m1 = l
        m2 = k - m1

        max_left = max(
            nums1[m1 - 1] if m1 > 0 else -inf,
            nums2[m2 - 1] if m2 > 0 else -inf
        )
        if (n1 + n2) & 1:
            return max_left
        min_right = min(
            nums1[m1] if m1 < n1 else inf,
            nums2[m2] if m2 < n2 else inf
        )
        return (max_left + min_right) / 2.


# @lc code=end

