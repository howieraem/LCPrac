#
# @lc app=leetcode id=1802 lang=python3
#
# [1802] Maximum Value at a Given Index in a Bounded Array
#

# @lc code=start
class Solution:
    # T: O(log(maxSum))
    # S: O(1)
    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        maxSum -= n  # so that nums[i] >= 0 will always be satisfied
        l = 0
        r = maxSum
        while l < r:
            m = (l + r + 1) >> 1
            # binary search find right most to maximize nums[index]
            if self.test_sum(n, index, m) <= maxSum:
                l = m
            else:
                r = m - 1
        return l + 1

    def test_sum(self, n: int, index: int, m: int):
        i1 = max(m - index, 0)
        i2 = max(m - ((n - 1) - index), 0)
        # sum of nums[i1...m] and nums[m...i2]
        return (((m + i1) * (m - i1 + 1)) >> 1) + (((m + i2) * (m - i2 + 1)) >> 1) - m
        

# @lc code=end

