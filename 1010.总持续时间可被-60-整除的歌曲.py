#
# @lc app=leetcode.cn id=1010 lang=python3
#
# [1010] 总持续时间可被 60 整除的歌曲
#
from typing import List

# @lc code=start
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        ans = 0
        remainder_cnts = [0] * 60

        for t in time:
            remainder = t % 60

            # If the sum of remainders of two numbers divided by 60
            # equals 60, then the sum of these two numbers is divisible
            # by 60.
            target_remainder = 60 - remainder if remainder else 0
            ans += remainder_cnts[target_remainder]
            remainder_cnts[remainder] += 1
        return ans

# @lc code=end
