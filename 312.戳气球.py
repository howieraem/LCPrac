#
# @lc app=leetcode.cn id=312 lang=python3
#
# [312] 戳气球
#

# @lc code=start
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]     # deal with boundary cases
        n = len(nums)
        dp = [[0]*n for _ in range(n)]

        # 开始dp：i为begin，j为end，k为在i、j区间划分子问题时的边界
        for i in range(n-2, -1, -1):
            for j in range(i+2, n):
                res = 0
                for k in range(i+1, j):
                    left = dp[i][k]
                    right = dp[k][j]
                    res = max(res, left+nums[i]*nums[k]*nums[j]+right)
                dp[i][j] = res
        return dp[0][-1]

        
# @lc code=end

