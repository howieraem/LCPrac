#
# @lc app=leetcode.cn id=90 lang=python3
#
# [90] 子集 II
#
# from typing import List
from typing import List

# @lc code=start
class Solution:
    # T: O(n * 2 ^ n)
    # S: O(the no. of unique numbers)
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        n = len(nums)
        def backtrack(path, start_idx):
            res.append(path[:])
            for i in range(start_idx, n):
                if i != start_idx and nums[i - 1] == nums[i]:
                    continue
                path.append(nums[i])
                backtrack(path, i + 1)
                path.pop()
        backtrack([], 0)
        return res

# @lc code=end
# s = Solution()
# print(s.subsetsWithDup([1,2,2,2]))
