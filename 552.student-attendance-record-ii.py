#
# @lc app=leetcode id=552 lang=python3
#
# [552] Student Attendance Record II
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n)
    def checkRecord(self, n: int) -> int:
        MOD = 1000000007

        # dp[i][j][k] means the number of valid seqs of length i where 
        # can be at most j A's and at most k trailing L's in each of
        # the seqs.
        dp = [[[0] * 3 for _ in range(2)] for _ in range(n + 1)]

        dp[0] = [[1, 1, 1], [1, 1, 1]]
        for i in range(1, n + 1):
            for j in range(2):
                for k in range(3):
                    val = dp[i - 1][j][2]  # seq[i] = P
                    if j > 0:
                        val = (val + dp[i - 1][j - 1][2]) % MOD  # seq[i] = A
                    if k > 0:
                        val = (val + dp[i - 1][j][k - 1]) % MOD  # seq[i] = L
                    dp[i][j][k] = val
        return dp[n][1][2]        

# @lc code=end

