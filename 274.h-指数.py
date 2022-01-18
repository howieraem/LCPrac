#
# @lc app=leetcode.cn id=274 lang=python3
#
# [274] H 指数
#

# @lc code=start
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort()
        cnt, l = 0, len(citations)
        while cnt < l and citations[l - cnt - 1] > cnt:
            cnt += 1
        return cnt
# @lc code=end

