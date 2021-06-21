#
# @lc app=leetcode.cn id=77 lang=python3
#
# [77] 组合
#
from typing import List

# @lc code=start
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        assert n >= k
        if not n or not k:
            return []
        res = []
        self.backtrack(res, [], list(range(1, n+1)), k)
        return res

    def backtrack(self, res, path, remain, k):
        if not k:
            res.append(path[:])
            return
        for i, n in enumerate(remain):
            path.append(n)
            self.backtrack(res, path, remain[i+1:], k-1)
            path.pop()
            

# @lc code=end
# s = Solution()
# print(s.combine(3, 2))
