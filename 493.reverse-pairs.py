#
# @lc app=leetcode id=493 lang=python3
#
# [493] Reverse Pairs
#
from typing import List

# @lc code=start
class Solution:
    # Divide and conquer, integrated in merge sort
    # T: O(n * log(n))
    # S: O(n)
    def reversePairs(self, nums: List[int]) -> int:
        return self.helper(nums, 0, len(nums) - 1)

    def helper(self, nums, l, r):
        if l >= r:
            return 0
        
        m = l + ((r - l) >> 1)

        # At this point, nums[l...m] and nums[m+1...r] have been sorted respectively
        ans = self.helper(nums, l, m) + self.helper(nums, m + 1, r)

        i = l
        j = m + 1
        k = 0
        p = m + 1
        merged = [0] * (r - l + 1)

        # Merge process
        while i <= m:
            while p <= r and nums[i] > (nums[p] << 1):
                p += 1

            # Example: if nums[l...m] = [4,6,8] and nums[m+1...r] = [1,2,3],
            # 4 -> {1, 2}, 2 pairs
            # 6 -> {1, 2, 3}, 3 pairs
            # 8 -> {1, 2, 3}, 3 pairs
            ans += p - (m + 1)
            
            # ordinary merge sort process
            while j <= r and nums[i] >= nums[j]:
                merged[k] = nums[j]
                j += 1
                k += 1
            merged[k] = nums[i]
            i += 1
            k += 1

        while j <= r:
            merged[k] = nums[j]
            j += 1
            k += 1

        nums[l:r + 1] = merged
        return ans

# @lc code=end

