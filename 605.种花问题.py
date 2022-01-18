#
# @lc app=leetcode.cn id=605 lang=python3
#
# [605] 种花问题
#

# @lc code=start
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        i = cnt = 0
        while i < len(flowerbed):
            if (
                not flowerbed[i] and
                (not i or not flowerbed[i - 1]) and
                ((i == len(flowerbed) - 1) or not flowerbed[i + 1]) 
            ):
                flowerbed[i] = 1
                i += 1
                cnt += 1 
            if cnt >= n:
                return True
            i += 1
        return False
            
        
# @lc code=end

