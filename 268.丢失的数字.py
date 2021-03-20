#
# @lc app=leetcode.cn id=268 lang=python3
#
# [268] 丢失的数字
#

# @lc code=start
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        # same idea as finding the number that appears once while others appear twice (index and the number itself).
        missing = l = len(nums)
        for i in range(l):
            missing ^= (i ^ nums[i])
        return missing

# @lc code=end

