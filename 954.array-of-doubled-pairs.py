#
# @lc app=leetcode id=954 lang=python3
#
# [954] Array of Doubled Pairs
#
from collections import Counter
from typing import List

# @lc code=start
class Solution:
    # T: O(n + k * log(k)), k := the number of unique numbers
    # S: O(n)
    def canReorderDoubled(self, arr: List[int]) -> bool:
        cnts = Counter(arr)
        for key in sorted(cnts, key=abs):
            if cnts[key] > cnts[key << 1]:
                return False
            cnts[key << 1] -= cnts[key]
        return True

# @lc code=end

