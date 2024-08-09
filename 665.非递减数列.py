#
# @lc app=leetcode.cn id=665 lang=python3
#
# [665] 非递减数列
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def checkPossibility(self, nums: List[int]) -> bool:
        cnt = 0
        for i in range(1, len(nums)):
            if nums[i - 1] > nums[i]:
                cnt += 1
                if cnt >= 2:
                    return False
                if i - 2 >= 0 and nums[i - 2] > nums[i]:
                    nums[i] = nums[i - 1]   # modify to avoid affecting next comparison
        return True

# @lc code=end

