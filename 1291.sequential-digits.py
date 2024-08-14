#
# @lc app=leetcode id=1291 lang=python3
#
# [1291] Sequential Digits
#
from collections import deque
from typing import List

# @lc code=start
class Solution:
    '''
    # Trivial solution: enumerate all possible options
    # T: O(log(high) ^ 2), high = 10^9
    # S: O(log(high) ^ 2)
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ALL = (12, 23, 34, 45, 56, 67, 78, 89, 
               123, 234, 345, 456, 567, 678, 789,
               1234, 2345, 3456, 4567, 5678, 6789,
               12345, 23456, 34567, 45678, 56789,
               123456, 234567, 345678, 456789,
               1234567, 2345678, 3456789,
               12345678, 23456789,
               123456789)
        
        res = []
        for x in ALL:
            if x >= low:
                if x > high:
                    break
                res.append(x)

        return res
    '''
    
    # BFS
    # T: O(log(high) ^ 2), high = 10^9
    # S: O(log(high) ^ 2)
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        q = deque()
        for x in range(1, 10):
            q.append(x)
        
        res = []
        while len(q) != 0:
            x = q.popleft()
            if x >= low:
                if x > high:
                    break
                res.append(x)
            last_digit = x % 10
            if last_digit < 9:
                q.append(x * 10 + (last_digit + 1))
        return res

# @lc code=end

