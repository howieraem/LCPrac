#
# @lc app=leetcode id=216 lang=python3
#
# [216] Combination Sum III
#
from typing import *

# @lc code=start
class Solution:
    # T: O(k * mCk), m := 9
    # S: O(k)
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        MAX = 9
        res = []

        def backtrack(start_num: int, cur_sum: int, path: List[int]):
            if len(path) == k:
                if cur_sum == n:
                    res.append(path[:])
                return
            
            for x in range(start_num, MAX + 1):
                if cur_sum + x > n:
                    break
                path.append(x)
                backtrack(x + 1, cur_sum + x, path)
                path.pop()

        backtrack(1, 0, [])

        return res



# @lc code=end

