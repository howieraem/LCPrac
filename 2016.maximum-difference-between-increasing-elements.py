#
# @lc app=leetcode id=2016 lang=python3
#
# [2016] Maximum Difference Between Increasing Elements
#
from typing import List

# @lc code=start
class Solution:
    # Same as Q121
    # T: O(n)
    # S: O(1)
    def maximumDifference(self, nums: List[int]) -> int:
        cur_min = nums[0]
        ans = 0
        for i in range(1, len(nums)):
            cur_min = min(cur_min, nums[i])
            ans = max(ans, nums[i] - cur_min)
        return ans if ans > 0 else -1 
        
# @lc code=end

