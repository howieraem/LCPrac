#
# @lc app=leetcode.cn id=40 lang=python3
#
# [40] 组合总和 II
#
from typing import List

# @lc code=start
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        """Solution with DFS."""
        candidates.sort()   # for convenient exclusion of repeated elements
        res = []
        self.backtrack(res, candidates, [], target)
        return res

    def backtrack(self, res, candidates, path, remain):
        if not remain:
            res.append(path[:])     # append a copy of current path
            return
        for i, n in enumerate(candidates):
            if n > remain:
                break   # as candidates are sorted
            if i > 0 and candidates[i-1] == n:
                # only consider the first of the repeated numbers as
                # it will branch into more cases
                continue    
            path.append(n)
            self.backtrack(res, candidates[i+1:], path, remain-n)
            path.pop()  # stack, last in first out

# @lc code=end
s = Solution()
print(s.combinationSum2([10, 1, 2, 7, 6, 1, 5], 8))
