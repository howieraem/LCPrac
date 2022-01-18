#
# @lc app=leetcode.cn id=120 lang=python3
#
# [120] 三角形最小路径和
#
from typing import List

# @lc code=start
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        """
        Original state transition:
                        dp[i-1][0]+tr[i][0], j=0
            dp[i][j] = { dp[i-1][j-1]+tr[i][i], j=i
                        min(dp[i-1][j-1], dp[i-1][j])+tr[i][j], otherwise

        This can be simplified to
            dp[j] = min(dp[j-1], dp[j]) + tr[i][j] with j enumerated reversely from i to 0.

        If possible, one may modify the original triangle inplace to avoid any extra space.
        """       

        if not triangle or not triangle[0]:
            return 0
        n = len(triangle)
        dp = [0] * n
        dp[0] = triangle[0][0]

        for i in range(1, n):
            dp[i] = dp[i-1] + triangle[i][i]
            for j in range(i - 1, 0, -1):
                dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j]
            dp[0] += triangle[i][0]
        return min(dp)

# @lc code=end
# tr = [
#     [2],
#     [3, 4],
#     [6, 5, 7],
#     [4, 1, 8, 3],
# ]
# s = Solution()
# print(s.minimumTotal(tr))
