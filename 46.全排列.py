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

    def backtrack(self, res, path, candidates):
        if len(candidates) == 0:
            res.append(path[:])
            return
        for i, num in enumerate(candidates):
            path.append(num)

            # ignore candidates[i] and use the other elements
            self.backtrack(res, path, candidates[:i]+candidates[i+1:])
            
            path.pop()
    
# @lc code=end
s = Solution()
print(s.permute([1,2,3,4]))
