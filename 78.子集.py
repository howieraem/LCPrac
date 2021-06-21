#
# @lc app=leetcode.cn id=78 lang=python3
#
# [78] 子集
#
from typing import List

# @lc code=start
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        def backtrack(path, nums):
            if len(path) <= n:
                res.append(path[:])
                for i, num in enumerate(nums):
                    path.append(num)
                    backtrack(path, nums[i+1:])
                    path.pop()
        backtrack([], nums)
        return res
    
# @lc code=end
# s = Solution()
# print(s.subsets([2, 1, 3]))
