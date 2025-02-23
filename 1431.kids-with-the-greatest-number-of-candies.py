#
# @lc app=leetcode id=1431 lang=python3
#
# [1431] Kids With the Greatest Number of Candies
#
from typing import List

# @lc code=start
class Solution:
    # Array
    # T: O(n)
    # S: O(1)
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        pre_max = max(candies)
        res = [False] * len(candies)
        for i, x in enumerate(candies):
            res[i] = (x + extraCandies >= pre_max)
        return res

# @lc code=end

