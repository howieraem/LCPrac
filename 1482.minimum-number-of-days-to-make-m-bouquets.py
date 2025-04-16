#
# @lc app=leetcode id=1482 lang=python3
#
# [1482] Minimum Number of Days to Make m Bouquets
#
from typing import List

# @lc code=start
class Solution:
    # Binary Search
    # T: O(n * log(max(arr) - min(arr)))
    # S: O(1)
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        n = len(bloomDay)
        if n < m * k:
            return -1
        
        l = 1_000_000_000
        r = 1
        for x in bloomDay:
            l = min(l, x)
            r = max(r, x)

        def is_invalid(days):
            bouq = 0
            adj_flower = 0

            for i in range(n):
                if bloomDay[i] > days:
                    adj_flower = 0
                else:
                    adj_flower += 1
                    
                    if adj_flower == k:
                        bouq += 1
                        if bouq >= m:
                            return False
                        
                        adj_flower = 0

            return True

        while l < r:
            mid = l + ((r - l) >> 1)
            if is_invalid(mid):
                l = mid + 1
            else:
                r = mid

        return l
        


# @lc code=end

