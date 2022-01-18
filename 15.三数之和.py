#
# @lc app=leetcode.cn id=15 lang=python3
#
# [15] 三数之和
#
from typing import List

# @lc code=start
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        if n < 3:
            return []
        nums.sort()     # O(nlog(n)), timsort
        res = []
        for i in range(n - 2):
            x = nums[i]
            if x > 0:   
                # in a sorted list, sum of any 3 nums to the right of x is always greater than 0
                return res
            if i > 0 and x == nums[i-1]:
                continue    # avoid repetitions
            left, right = i + 1, n - 1
            while left < right:
                y, z = nums[left], nums[right]
                if not x + y + z:    # == 0
                    res.append([x, y, z])
                    while left < right and nums[left] == nums[left+1]:
                        left += 1   # avoid repetitions
                    while left < right and nums[right] == nums[right-1]:
                        right -= 1  # avoid repetitions
                    left += 1
                    right -= 1
                elif x + y + z > 0:
                    right -= 1
                else:
                    left += 1
        return res


    """
    original solution, O(n^3), too slow:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3:
            return []
        sn = set(nums)
        ret_sets = []
        l = len(nums)
        ret = []
        for i, m in enumerate(nums):
            for j, n in enumerate(nums):
                if i == j:
                    continue
                mn = -m-n
                if mn in sn:
                    for k, o in enumerate(nums):
                        if o == mn and k != i and k != j:
                            ans = [m, n, mn]
                            anss = set(ans)
                            if anss not in ret_sets:
                                ret.append([m, n, mn])
                                ret_sets.append(set(ans))
        return ret
    """

# @lc code=end
s = Solution()
print(s.threeSum([-1, 0, 1, 2, -1, -4]))
