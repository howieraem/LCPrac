#
# @lc app=leetcode.cn id=15 lang=python3
#
# [15] 三数之和
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n ^ 2)
    # S: O(n) timsort
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        TARGET = 0
        n = len(nums)
        if n < 3:
            return []

        nums.sort()     # O(nlog(n)), timsort

        res = []
        for i in range(n - 2):
            x = nums[i]
            if x > TARGET:   
                # in a sorted list, sum of any 3 nums to the right of x is always greater than target
                return res
            if i > 0 and x == nums[i - 1]:
                continue    # avoid duplicates
            
            # Below is the same as Two Sum II Q167
            left, right = i + 1, n - 1
            while left < right:
                s = x + nums[left] + nums[right]
                if s == TARGET:    # == 0
                    res.append([x, nums[left], nums[right]])

                    # avoid duplicates
                    while left < right and nums[left] == nums[left+1]:
                        left += 1   
                    while left < right and nums[right] == nums[right-1]:
                        right -= 1

                    left += 1
                    right -= 1
                elif s > TARGET:
                    right -= 1
                else:
                    left += 1
        return res

# @lc code=end
