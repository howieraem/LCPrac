#
# @lc app=leetcode.cn id=81 lang=python3
#
# [81] 搜索旋转排序数组 II
#
from typing import List

# @lc code=start
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        """Best case: no repetition, O(log(N)); worse case: mostly repeated, O(N)."""
        low, high = 0, len(nums)-1
        while low <= high:
            mid = (low + high) >> 1
            if nums[mid] == target:
                return True
            elif nums[low] < nums[mid]:
                if nums[low] <= target < nums[mid]:
                    high = mid-1    # search in lower half
                else:   # target > nums[mid]
                    low = mid+1     # search in upper half
            elif nums[low] == nums[mid]:
                low += 1    # shift one to exclude a repetition
            else:
                if nums[mid] < target <= nums[high]:
                    low = mid+1     # search in upper half
                else:   # target < nums[mid]
                    high = mid-1    # search in lower half
        return False

# @lc code=end
# s = Solution()
# nums = [1, 3, 1, 1, 1]
# print(s.search(nums, 3))
