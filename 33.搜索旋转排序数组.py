#
# @lc app=leetcode.cn id=33 lang=python3
#
# [33] 搜索旋转排序数组
#
from typing import List

# @lc code=start
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        if not n:
            return -1
        low, high = 0, n-1
        while low <= high:
            mid = (low + high) >> 1
            if nums[mid] == target:
                return mid
            if nums[low] <= nums[mid]:
                if nums[low] <= target < nums[mid]:
                    high = mid-1    # search in lower half
                else:   # target > nums[mid]
                    low = mid+1     # search in upper half
            else:
                if nums[mid] < target <= nums[high]:
                    low = mid+1     # search in upper half
                else:   # target < nums[mid]
                    high = mid-1    # search in lower half
        return -1
            

# @lc code=end
s = Solution()
print(s.search([4, 5, 6, 7, 0, 1, 2], 0))
