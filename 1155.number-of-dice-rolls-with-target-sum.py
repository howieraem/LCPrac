#
# @lc app=leetcode id=1155 lang=python3
#
# [1155] Number of Dice Rolls With Target Sum
#

# @lc code=start
class Solution:
    # 3D DP
    # T: O(n * k * target)
    # S: O(target)
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        MOD = 1_000_000_007
        dp = [0] * (target + 1)
        dp[0] = 1

        for _ in range(n):
            dp_nxt = [0] * (target + 1)
            for x in range(1, k + 1):   # coins [1...k]
                for j in range(x, target + 1):
                    dp_nxt[j] = (dp_nxt[j] + dp[j - x]) % MOD

            dp = dp_nxt[:]  # state compression
        
        return dp[target]

        
# @lc code=end

