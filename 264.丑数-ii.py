#
# @lc app=leetcode.cn id=264 lang=python3
#
# [264] 丑数 II
#

# @lc code=start
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        nums = [1, ]
        i2 = i3 = i5 = 0
        for _ in range(1, n):
            ugly = min(nums[i2] * 2, nums[i3] * 3, nums[i5] * 5)
            nums.append(ugly)

            # Don't use elif below because ugly can be multiples of any of {2, 3, 5},
            # and should be incorporated only once
            if ugly == nums[i2] * 2:
                i2 += 1
            if ugly == nums[i3] * 3:
                i3 += 1
            if ugly == nums[i5] * 5:
                i5 += 1
        return nums[-1]

# @lc code=end

