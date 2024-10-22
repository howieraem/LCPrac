#
# @lc app=leetcode id=280 lang=python3
#
# [280] Wiggle Sort
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Greedy
        # - if i is odd, then nums[i] >= nums[i - 1]
        # - if i is even, then nums[i] <= nums[i - 1]
        # Thus, we only need to fix the anti-patterns in nums.
        # 
        # Proof:
        #   Suppose nums[1, 2, ..., i] follows the rule.
        #   If i is odd, we need to prove by swapping, i + 1 will follow the rule as well.
        #   If nums[i] >= nums[i + 1]: 
        #       The rule is followed
        #   Else: 
        #       Swap nums[i] and nums[i + 1]
        #       Then we have nums[i - 1] <= nums[i] and nums[i] < nums[i + 1]
        #       and nums[i - 1] <= nums[i + 1] also follows the rule.
        #   This can be proven for even indices in a similar way.
        for i in range(1, len(nums)):
            if ((i & 1) == 0) == (nums[i] > nums[i - 1]):
                nums[i - 1], nums[i] = nums[i], nums[i - 1]

        
# @lc code=end

