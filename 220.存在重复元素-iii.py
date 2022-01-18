#
# @lc app=leetcode.cn id=220 lang=python3
#
# [220] 存在重复元素 III
#

# @lc code=start
class Solution:
    # Inspired by bucket sort 
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        if t < 0:
            return False
        d = {}
        self.w = t + 1

        for i, num in enumerate(nums):
            m = self.getBucketID(num)
            if (
                m in d or
                (m - 1 in d and abs(num - d[m - 1]) <= t) or
                (m + 1 in d and abs(num - d[m + 1]) <= t)
            ):
                return True
            d[m] = num
            if i >= k:
                del d[self.getBucketID(nums[i - k])]
        return False

    def getBucketID(self, x):  
        # bucket size is t + 1
        return x // self.w

# @lc code=end

