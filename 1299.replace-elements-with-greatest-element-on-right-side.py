#
# @lc app=leetcode id=1299 lang=python3
#
# [1299] Replace Elements with Greatest Element on Right Side
#
from typing import *

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def replaceElements(self, arr: List[int]) -> List[int]:
        cur_max = -1
        for i in range(len(arr) - 1, -1, -1):
            cur = arr[i]
            arr[i] = cur_max
            cur_max = max(cur_max, cur)
        return arr

# @lc code=end

