#
# @lc app=leetcode id=1296 lang=python3
#
# [1296] Divide Array in Sets of K Consecutive Numbers
#
from collections import Counter
from typing import *

# @lc code=start
class Solution:
    # hash map + sorting + greedy
    # Same as Q846
    # T: O(n + m * log(m)) amortized, m := the number of unique numbers
    # S: O(m)
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        if len(nums) % k:
            return False
        
        cnts = Counter(nums)
        
        for x in sorted(cnts.keys()):
            if cnts[x] > 0:
                required = cnts[x]

                # Note that k may not contribute to time complexity.
                # https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/discuss/470238/JavaC++Python-Exactly-Same-as-846.-Hand-of-Straights/1001094
                for y in range(x + 1, x + k):
                    if y not in cnts or cnts[y] < required:
                        return False

                    cnts[y] -= required   # IMPORTANT: consume next numbers
        
        return True
        
# @lc code=end

