#
# @lc app=leetcode.cn id=46 lang=python3
#
# [46] 全排列
#
from typing import List

# @lc code=start
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        self.backtrack(res, [], nums)
        return res

    def backtrack(self, res, path, remain):
        if not remain:
            res.append(path[:])
            return
        for i, num in enumerate(remain):
            path.append(num)
            self.backtrack(res, path, remain[:i]+remain[i+1:])  # ignore remain[i] and use the other elements
            path.pop()
    
# @lc code=end
s = Solution()
print(s.permute([1,2,3,4]))
