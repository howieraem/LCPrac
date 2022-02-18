#
# @lc app=leetcode id=26 lang=python3
#
# [26] Remove Duplicates from Sorted Array
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        cur, pre = 1, 0
        while cur < n:
            if nums[pre] != nums[cur]:
                pre += 1
                nums[pre] = nums[cur]
            cur += 1
        return pre + 1

# @lc code=end

