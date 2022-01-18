#
# @lc app=leetcode.cn id=763 lang=python3
#
# [763] 划分字母区间
#

# @lc code=start
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        last = [0]*26
        n = len(S)
        for i, c in enumerate(S):
            last[ord(c) - 97] = i   # ord('a') = 97
        
        res = []
        start = end = 0
        for i, c in enumerate(S):
            end = max(end, last[ord(c) - 97])
            if i == end:
                res.append(end - start + 1)
                start = end + 1
        return res

# @lc code=end

