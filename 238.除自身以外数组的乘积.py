#
# @lc app=leetcode.cn id=238 lang=python3
#
# [238] 除自身以外数组的乘积
#
from typing import List

# @lc code=start
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = suffix = 1
        n = len(nums)
        ans = [1]*n
        for i in range(n):
            ans[i] *= prefix
            ans[n-i-1] *= suffix
            prefix *= nums[i]
            suffix *= nums[n-i-1]
        return ans

# @lc code=end

