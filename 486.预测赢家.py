#
# @lc app=leetcode.cn id=486 lang=python3
#
# [486] 预测赢家
#

# @lc code=start
class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        if not n % 2:   # even number of numbers
            return True
        
        # odd number of numbers with optimized DP space usage
        '''
        dp = [0] * n
        for i, num in enumerate(nums):
            dp[i] = num
        '''
        dp = nums[:]
        for i in range(n-2, -1, -1):
            for j in range(i+1, n):
                '''
                当 i < j 时，当前玩家可以选择nums[i]或nums[j]，
                然后轮到另一个玩家在数组剩下的部分选取数字。
                在两种方案中，当前玩家会选择最优的方案，
                使得自己的分数最大化。
                因此可以得到如下状态转移方程：
                dp[i][j] = max(nums[i]−dp[i+1][j], nums[j]−dp[i][j−1])

                分析状态转移方程可以看到，dp[i][j]的值只和dp[i+1][j]与dp[i][j−1]有关，
                即在计算dp的第i行的值时，只需要使用到dp的第i行和第i+1行的值，
                因此可以使用一维数组代替二维数组，对空间进行优化。
                '''
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j-1])
        return dp[-1] >= 0

# @lc code=end
