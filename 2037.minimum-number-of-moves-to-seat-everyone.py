#
# @lc app=leetcode id=2037 lang=python3
#
# [2037] Minimum Number of Moves to Seat Everyone
#
from typing import List

# @lc code=start
class Solution:
    # Sorting + two pointers
    # T: O(n * log(n))
    # S: O(n) timsort
    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        seats.sort()
        students.sort()

        ans = 0
        for s, t in zip(seats, students):
            ans += abs(s - t)
        
        return ans

# @lc code=end

