#
# @lc app=leetcode.cn id=435 lang=python3
#
# [435] 无重叠区间
#

# @lc code=start
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0
        intervals.sort(key=lambda x: x[1])  # sort by interval ends
        ans = 0
        pre = intervals[0][1]
        for i in range(1, len(intervals)):
            if intervals[i][0] < pre:
                # overlapped
                ans += 1
            else:
                pre = intervals[i][1]
        return ans

        
# @lc code=end

