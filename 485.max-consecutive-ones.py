#
# @lc app=leetcode id=485 lang=python3
#
# [485] Max Consecutive Ones
#
from typing import *

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        cnt1 = 0
        ans = 0
        for x in nums:
            if x == 1:
                cnt1 += 1
                ans = max(ans, cnt1)
            else:
                cnt1 = 0
        return ans
        
# @lc code=end

