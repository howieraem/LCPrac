#
# @lc app=leetcode id=1360 lang=python3
#
# [1360] Number of Days Between Two Dates
#
from typing import *

# @lc code=start
class Solution:
    # T: O(len(date1) + len(date2))
    # S: O(1)
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        month_days = (31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)
        y1, m1, d1 = self.convertDateStr(date1)
        y2, m2, d2 = self.convertDateStr(date2)
        
        date1_days = \
            y1 * 365 + sum(month_days[i] for i in range(m1 - 1)) + d1 + self.countLeapYear(y1, m1)
        date2_days = \
            y2 * 365 + sum(month_days[i] for i in range(m2 - 1)) + d2 + self.countLeapYear(y2, m2)
        return abs(date1_days - date2_days)

    @staticmethod
    def convertDateStr(date: str) -> Tuple[int]:
        raw = date.split("-")
        return int(raw[0]), int(raw[1]), int(raw[2])

    @staticmethod
    def countLeapYear(y: int, m: int) -> int:
        y -= (m <= 2)  # leap year has no effect if month <= Feb
        return y // 4 - y // 100 + y // 400

# @lc code=end

