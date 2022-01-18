#
# @lc app=leetcode.cn id=1 lang=python3
#
# [1] 两数之和
#

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i, m in enumerate(nums):
            if target - m in d.keys():
                return [d[target-m], i]
            d[m] = i

# @lc code=end

