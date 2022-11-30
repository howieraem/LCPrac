#
# @lc app=leetcode id=846 lang=python3
#
# [846] Hand of Straights
#
from collections import Counter
from typing import *

# @lc code=start
class Solution:
    # Same as Q1296
    # T: O(n + m * log(m)) amortized, m := the number of unique numbers
    # S: O(m)
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize:
            return False
        cnts = Counter(hand)
        for x in sorted(cnts):
            if cnts[x] > 0:
                required = cnts[x]

                # Note that groupSize may not contribute to time complexity because each number in hand is used at most once.
                # https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/discuss/470238/JavaC++Python-Exactly-Same-as-846.-Hand-of-Straights/1001094
                for y in range(x + 1, x + groupSize):
                    if y not in cnts or cnts[y] < required:
                        return False
                    cnts[y] -= required
        return True

# @lc code=end

