#
# @lc app=leetcode.cn id=18 lang=python3
#
# [18] 四数之和
#
# from typing import List

# @lc code=start
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        if n < 4:
            return []
        nums.sort()
        res = []
        for i in range(n-3):
            w = nums[i]
            if i > 0 and w == nums[i-1]:
                continue    # avoid repetitions
            for j in range(i+1, n-2):
                x = nums[j]
                if j > i+1 and x == nums[j-1]:
                    continue    # avoid repetitions
                left, right = j+1, n-1
                while left < right:
                    y, z = nums[left], nums[right]
                    s = w + x + y + z
                    if s > target:
                        right -= 1
                    elif s < target:
                        left += 1
                    else:
                        res.append([w, x, y, z])
                        while left < right and nums[left] == nums[left+1]:
                            left += 1   # avoid repetitions
                        while left < right and nums[right] == nums[right-1]:
                            right -= 1  # avoid repetitions
                        left += 1
                        right -= 1
        return res

# @lc code=end
# s = Solution()
# print(s.fourSum([-1, 0, 1, 2, -1, -4], -1))
