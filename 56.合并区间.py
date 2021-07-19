#
# @lc app=leetcode.cn id=56 lang=python3
#
# [56] 合并区间
#
from typing import List

# @lc code=start
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) < 2:
            return intervals
        intervals.sort(key=lambda x: x[0])
        res = []
        start, end = intervals[0]
        for left, right in intervals[1:]:
            # since sorted, right will never be less than start, and left >= start always
            if left > end:
                res.append([start, end])
                start, end = left, right
            elif right > end:
                end = right
        res.append([start, end])    # don't forget the last one
        return res
                

# @lc code=end
