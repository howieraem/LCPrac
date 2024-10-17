#
# @lc app=leetcode id=744 lang=python3
#
# [744] Find Smallest Letter Greater Than Target
#
from typing import List

# @lc code=start
class Solution:
    # binary search
    # T: O(log(n))
    # S: O(1)
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        l = 0
        r = len(letters) - 1

        while l <= r:
            m = l + ((r - l) >> 1)
            if letters[m] > target:
                r = m - 1
            else:
                l = m + 1
        
        return letters[l] if l < len(letters) else letters[0]

# @lc code=end

