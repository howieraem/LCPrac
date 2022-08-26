#
# @lc app=leetcode id=2178 lang=python3
#
# [2178] Maximum Split of Positive Even Integers
#
from typing import List

# @lc code=start
class Solution:
    # Greedy
    # T: O(sqrt(finalSum)), derived from the sum of an arithmetic progression
    # S: O(1)
    def maximumEvenSplit(self, finalSum: int) -> List[int]:
        if finalSum & 1:  # odd sum, impossible to split
            return []

        res = []
        i = 2
        cur_sum = 0
        # Since we want the maximum number of unique even numbers,
        # each iteration we use the smallest even number available.
        # Add 2, 4, 6, ... until the sum approaches finalSum.
        while cur_sum + i <= finalSum:
            res.append(i)
            cur_sum += i
            i += 2
        
        # For the last element, just add the remaining difference
        res[-1] += finalSum - cur_sum
        return res


# @lc code=end

