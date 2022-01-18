#
# @lc app=leetcode.cn id=16 lang=python3
#
# [16] 最接近的三数之和
#
from typing import List

# @lc code=start
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        n = len(nums)
        # if n < 3:
        #     raise ValueError
        nums.sort()     # O(nlog(n))
        # print(nums)
        ans = sum(nums[:3])     # nums[0]+nums[1]+nums[2]
        for i in range(n-2):
            if i > 0 and nums[i] == nums[i-1]:
                continue    # avoid repetitions
            left, right = i+1, n-1
            while left < right:
                sum3 = nums[i] + nums[left] + nums[right]
                if abs(target - sum3) < abs(target - ans):
                    ans = sum3
                if sum3 > target:
                    right -= 1
                elif sum3 < target:
                    left += 1
                else:
                    return ans
        return ans

    """
    original solution, but there can be less variables and if-else:

    def threeSumClosest(self, nums: List[int], target: int) -> int:
        n = len(nums)
        # if n < 3:
        #     raise ValueError
        nums.sort()
        # print(nums)
        min_delta = 1e4+3e3  # max. possible difference given hints
        prev_sum = 0
        for i, x in enumerate(nums):
            if i > 0 and nums[i] == nums[i-1]:
                continue    # avoid repetitions
            left, right = i+1, n-1
            while left < right:
                y, z = nums[left], nums[right]
                sum3 = x + y + z
                delta = target - sum3
                adelta = abs(delta)
                if delta < 0:
                    # print('c1', x, y, z, delta)
                    if adelta < min_delta:
                        min_delta = adelta
                        prev_sum = sum3
                    # else:
                    #     return prev_sum
                    while left < right and nums[right] == nums[right-1]:
                        right -= 1  # avoid repetitions
                    right -= 1
                elif delta > 0:
                    # print('c2', x, y, z, delta)
                    if adelta < min_delta:
                        min_delta = adelta
                        prev_sum = sum3
                    # else:
                    #     return prev_sum
                    while left < right and nums[left] == nums[left+1]:
                        left += 1   # avoid repetitions
                    left += 1
                else:
                    return target
        return prev_sum
    """

# @lc code=end
s = Solution()
print(s.threeSumClosest([1, 2, 4, 8, 16, 32, 64, 128], 82))
