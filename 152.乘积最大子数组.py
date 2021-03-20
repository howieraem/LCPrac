#
# @lc app=leetcode.cn id=152 lang=python3
#
# [152] 乘积最大子数组
#

# @lc code=start
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        curr_max, imax, imin = float('-inf'), 1, 1
        for num in nums:
            if num < 0:
                imax, imin = imin, imax
            imax = max(imax*num, num)
            imin = min(imin*num, num)
            curr_max = max(imax, curr_max)
        return curr_max

# @lc code=end

