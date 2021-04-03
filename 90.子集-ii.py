#
# @lc app=leetcode.cn id=90 lang=python3
#
# [90] 子集 II
#
# from typing import List

# @lc code=start
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        n = len(nums)
        def backtrack(path, nums):
            if len(path) <= n:
                res.append(path[:])
                for i in range(len(nums)):
                    num = nums[i]
                    if i and nums[i-1] == num:
                        continue
                    path.append(num)
                    backtrack(path, nums[i+1:])
                    path.pop()
        backtrack([], nums)
        return res

# @lc code=end
# s = Solution()
# print(s.subsetsWithDup([1,2,2,2]))
