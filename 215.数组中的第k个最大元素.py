#
# @lc app=leetcode.cn id=215 lang=python3
#
# [215] 数组中的第K个最大元素
#
from random import shuffle

# @lc code=start
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        shuffle(nums)   # randomize to get better pivots
        l, r = 0, len(nums) - 1
        target = len(nums) - k  # kth largest, (n-k)th smallest
        while l < r:
            mid = self.quickSelect(nums, l, r)
            if mid == target:
                return nums[mid]
            if mid < target:
                l = mid + 1
            else:
                r = mid - 1
        return nums[l]

    @staticmethod
    def quickSelect(nums, l, r):
        i, j = l + 1, r
        while True:
            # nums[l] is pivot
            while i < r and nums[i] <= nums[l]:  
                # move the low index towards the back
                i += 1
            while l < j and nums[j] >= nums[l]:
                # move the high index towards the front
                j -= 1
            if i >= j:
                break
            nums[i], nums[j] = nums[j], nums[i]
        nums[l], nums[j] = nums[j], nums[l]
        return j    # index of pivot

# @lc code=end

