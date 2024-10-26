#
# @lc app=leetcode id=81 lang=python3
#
# [81] Search in Rotated Sorted Array II
#
from typing import List

# @lc code=start
class Solution:
    # T: O(log(n)) on average, O(n) worst
    # S: O(1)
    def search(self, nums: List[int], target: int) -> bool:
        l, r = 0, len(nums) - 1
        while l <= r:
            m = (l + r) >> 1
            if nums[m] == target:
                return True
            elif nums[m] < nums[l]:
                # pivot is on the left of m
                if nums[m] < target and target <= nums[r]:
                    # Check if target is on the right monotonic (sorted) segment
                    # on the right of m. If so, shift l. It is necessary to 
                    # check target <= nums[r] because numbers to the 
                    # left of the pivot are all greater than nums[r].
                    l = m + 1
                else:
                    r = m - 1
            elif nums[m] > nums[l]:
                # pivot is on the right of m
                if nums[l] <= target and target < nums[m]:
                    # Check if target is on the left monotonic (sorted) segment
                    # on the left of m. If so, shift r. It is necessary to  
                    # check target >= nums[l] because numbers to the 
                    # right of the pivot are all less than nums[l].
                    r = m - 1
                else:
                    l = m + 1
            else:
                # Different from Q33
                # In this case we have to linearly skip the duplicate,
                # because we cannot determine which side of m is sorted
                l += 1
        return False
        # return l < len(nums) and nums[l] == target

# @lc code=end

