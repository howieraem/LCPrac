#
# @lc app=leetcode id=717 lang=python3
#
# [717] 1-bit and 2-bit Characters
#
from typing import *

# @lc code=start
class Solution:
    # Greedy? + array
    # T: O(n) worst
    # S: O(1)
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        n = len(bits)
        if n == 0 or bits[n - 1] == 1:
            return False

        # If there are two 0s at the back, the answer is true no matter 
        # what the rest symbols are (e.g., ...1100, ...1000).

        # Since 2-bit chars can be either 10 or 11, we iterate backwards
        # from the second last bit to check if the number of contiguous 
        # bits 1 is odd. If so, the last character cannot be a 1-bit char. 
        # More specifically, if there is 1 right before the last element(...10), 
        # the outcome depends on the count of sequential 1:
        #   a) If there is odd amount of 1(e.g., 10, ...01110) the answer is 
        #      false as there is a single 1 without pair
        #   b) If it's even (e.g., 110, ...011110) the answer is true, as 0 
        #      at the end doesn't have anything to pair with
        ones = 0
        for i in range(n - 2, -1, -1):
            if bits[i] == 0:
                break
            ones += bits[i]
        
        return (ones & 1) == 0
# @lc code=end

