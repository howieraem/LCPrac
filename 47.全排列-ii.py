#
# @lc app=leetcode.cn id=47 lang=python3
#
# [47] 全排列 II
#
from typing import List

# @lc code=start
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        self.backtrack(res, [], nums)
        return res

    def backtrack(self, res, path, remain):
        if not remain:
            res.append(path[:])
            return
        for i, num in enumerate(remain):
            if i > 0 and remain[i-1] == num:
                continue
            path.append(num)
            self.backtrack(res, path, remain[:i]+remain[i+1:])
            path.pop()

# @lc code=end
s = Solution()
print(s.permuteUnique([1, 1, 2, 2]))

