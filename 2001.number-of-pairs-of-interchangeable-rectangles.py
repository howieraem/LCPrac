#
# @lc app=leetcode id=2001 lang=python3
#
# [2001] Number of Pairs of Interchangeable Rectangles
#
from collections import defaultdict
from typing import List

# @lc code=start02
class Solution:
    '''
    # Solution 1: use float ratio as key, may encounter precision problems
    # T: O(n)
    # S: O(n)
    def interchangeableRectangles(self, rectangles: List[List[int]]) -> int:
        freq = {}
        ans = 0
        for w, h in rectangles:
            ratio = w / h
            if ratio in freq:
               ans += freq[ratio] 
            freq[ratio] += 1
        return ans
    '''

    # Solution 2: use greatest common divisor to avoid float keys, then 
    # use the number of combination formula nC2 to get the result
    # T: O(n)
    # S: O(n)
    def interchangeableRectangles(self, rectangles: List[List[int]]) -> int:
        freq = defaultdict(int)
        for w, h in rectangles:
            gcd = self.gcd(w, h)
            freq[(w // gcd, h // gcd)] += 1
            # accumulate the result here like solution 1 is also correct
        
        ans = 0
        for v in freq.values():
            if v == 1:
                continue
            ans += ((v * (v - 1)) >> 1)  # nC2 = n! / (n-k)! * k = n * (n - 1) / 2
        return ans

    def gcd(self, x: int, y: int) -> int:
        return x if y == 0 else self.gcd(y, x % y)
        
# @lc code=end

