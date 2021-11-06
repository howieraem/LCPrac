#
# @lc app=leetcode.cn id=53 lang=python3
#
# [53] 最大子序和
#
from typing import List

# @lc code=start
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        cur_sum = 0
        ans = nums[0]
        for num in nums:
            cur_sum = max(cur_sum + num, num)
            ans = max(ans, cur_sum)
        return ans

# @lc code=end