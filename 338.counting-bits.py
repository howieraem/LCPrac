#
# @lc app=leetcode id=338 lang=python3
#
# [338] Counting Bits
#
from typing import *

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def countBits(self, n: int) -> List[int]:
        dp = [0 for _ in range(n + 1)]

        for i in range(1, n + 1):
            # if i % 2 == 0:
            #     dp[i] = dp[i // 2]  # divisible by 2, same count of bits 1
            # else:
            #     dp[i] = dp[i - 1] + 1  # not divisible by 2, add one more bit 1 

            dp[i] = dp[i >> 1] + (i & 1)

        return dp

# @lc code=end

