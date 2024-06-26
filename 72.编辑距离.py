#
# @lc app=leetcode.cn id=72 lang=python3
#
# [72] 编辑距离
#

# @lc code=start
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n1, n2 = len(word1), len(word2)
        dp = [[0]*(n2+1) for _ in range(n1+1)]
        # 第一行、第一列
        for i in range(1, n1 + 1):
            dp[i][0] = dp[i-1][0] + 1
        for j in range(1, n2 + 1):
            dp[0][j] = dp[0][j-1] + 1
        
        # 一般情况
        for i in range(1, n1+1):
            for j in range(1, n2+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
        return dp[-1][-1]


# @lc code=end
print(Solution().minDistance('intention', 'execution'))
