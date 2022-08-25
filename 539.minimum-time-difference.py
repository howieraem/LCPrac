#
# @lc app=leetcode id=539 lang=python3
#
# [539] Minimum Time Difference
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n + t)
    # S: O(t), t := 24h * 60min
    def findMinDifference(self, timePoints: List[str]) -> int:
        O = ord('0')
        T = 24 * 60
        minutes = [False] * T
        for t in timePoints:
            h = 10 * (ord(t[0]) - O) + (ord(t[1]) - O)
            m = 10 * (ord(t[3]) - O) + (ord(t[4]) - O)
            minute = h * 60 + m
            if minutes[minute]:
                return 0
            minutes[minute] = True
        
        ans = T
        cur_diff = T
        first = T
        last = -1

        # Check [00:00, 23:59], and find the first and the last times
        for t in range(T):
            if minutes[t]:
                if cur_diff < ans:
                    ans = cur_diff
                cur_diff = 1

                first = min(first, t)
                last = max(last, t)
            else:
                cur_diff += 1
        
        # Check wrap around
        ans = min(ans, T - last + first)
        return ans
    
    # Alternative approach: if n is much smaller than t, 
    # can sort the time points and find the minimum 
    # difference between adjacent pairs (incl. the pair
    # of the first t and the last t)

# @lc code=end

