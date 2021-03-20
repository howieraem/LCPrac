#
# @lc app=leetcode.cn id=136 lang=python3
#
# [136] 只出现一次的数字
#
# from typing import List

# @lc code=start
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        seen_once = 0
        for num in nums:
            seen_once = seen_once ^ num
        return seen_once

# @lc code=end
# print(Solution().singleNumber([1, 2, 4, 1, 2]))
