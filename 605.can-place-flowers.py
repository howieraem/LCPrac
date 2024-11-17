#
# @lc app=leetcode id=605 lang=python3
#
# [605] Can Place Flowers
#
from typing import *

# @lc code=start
class Solution:
    # Two pointers + simulation
    # T: O(n)
    # S: O(1)
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        if n <= 0:
            return True
        n_flowerbed = len(flowerbed)
        for i in range(n_flowerbed):
            if flowerbed[i] == 0 and (i == 0 or flowerbed[i - 1] == 0) and (i == n_flowerbed - 1 or flowerbed[i + 1] == 0):
                flowerbed[i] = 1
                n -= 1
                if n == 0:
                    return True
        
        return False


# @lc code=end

