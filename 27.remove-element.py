#
# @lc app=leetcode id=27 lang=python3
#
# [27] Remove Element
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0
        for x in nums:
            if x != val:
                nums[k] = x
                k += 1
        return k

# @lc code=end

