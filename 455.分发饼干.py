#
# @lc app=leetcode.cn id=455 lang=python3
#
# [455] 分发饼干
#

# @lc code=start
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        child = cookie = 0
        while child < len(g) and cookie < len(s):
            # if g[child] <= s[cookie]:
            #     child += 1
            child += (g[child] <= s[cookie])
            cookie += 1
        return child

# @lc code=end

