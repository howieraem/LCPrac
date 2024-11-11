#
# @lc app=leetcode id=790 lang=python3
#
# [790] Domino and Tromino Tiling
#

# @lc code=start
class Solution:
    # 1D DP
    # T: O(n)
    # S: O(n), or O(1) with state compression
    def numTilings(self, n: int) -> int:
        # pattern: https://s3-lc-upload.s3.amazonaws.com/users/zhengkaiwei/image_1519539268.png
        if n < 0:
            return 0
        if n <= 1:
            return 1
        if n == 2:
            return 2
        if n == 3:
            return 5
        MOD = 1_000_000_007
        
        '''
        dp = [0] * (n + 1)
        dp[0] = dp[1] = 1
        dp[2] = 2
        dp[3] = 5
        for i in range(4, n + 1):
            dp[i] = ((dp[i - 1] << 1) + dp[i - 3]) % MOD
        return dp[n]
        '''
        dp1 = 1
        dp2 = 2
        dp3 = 5
        for _ in range(4, n + 1):
            dp4 = ((dp3 << 1) + dp1) % MOD
            dp1 = dp2
            dp2 = dp3
            dp3 = dp4

        return dp4
        
# @lc code=end

