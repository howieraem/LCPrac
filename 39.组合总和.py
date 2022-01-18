#
# @lc app=leetcode.cn id=39 lang=python3
#
# [39] 组合总和
#
from typing import List

# @lc code=start
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        """Solution with DFS."""
        res = []
        self.backtrack(res, candidates, [], target)
        return res

    def backtrack(self, res, nums, path, remain):
        if not remain:
            res.append(path[:])     # append a copy of current path
            return
        for n in nums:
            if n > remain:
                # 剪枝, candidates not sorted
                continue    
            if path and n < path[-1]:   
                # avoid repeated combinations and ensure the combination is sorted
                continue
            path.append(n)
            self.backtrack(res, nums, path, remain-n)
            path.pop()  # stack, last in first out

    """
    Solution with dynamic programming:

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:    
        dp = {}     # every candidate is unique
        for i in range(1, target+1):    # all(candidates) >= 1, target itself inclusive
            dp[i] = []
        
        for i in range(1, target+1):    # all(candidates) >= 1, target itself inclusive
            for j in candidates:
                if i == j:
                    dp[i].append([i])
                elif i > j:
                    for k in dp[i-j]:
                        x = k[:]    # make a copy
                        x.append(j)
                        x.sort() # 升序，便于后续去重
                        if x not in dp[i]:
                            dp[i].append(x)
        return dp[target]
    """


# @lc code=end
s = Solution()
print(s.combinationSum([1], 2))
