#
# @lc app=leetcode.cn id=275 lang=python3
#
# [275] H 指数 II
#

# @lc code=start
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        left, right = 0, n - 1
        while left <= right:
            mid = (right - left) // 2 + left
            diff = n - mid
            if citations[mid] == diff:
                return diff
            if citations[mid] < diff:
                left = mid + 1
            else:
                right = mid - 1
        return n - left     # if all citations are greater than n

# @lc code=end

