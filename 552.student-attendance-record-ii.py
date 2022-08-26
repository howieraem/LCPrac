#
# @lc app=leetcode id=552 lang=python3
#
# [552] Student Attendance Record II
#
from typing import *

# @lc code=start
class Solution:
    MOD = 1000000007

    # Solution 1: DP
    # T: O(n)
    # S: O(1) after space optimization
    def checkRecord(self, n: int) -> int:
        # dp[i][j][k] means the number of valid seqs of length i where 
        # can be at most j A's and at most k trailing L's in each of
        # the seqs.
        # dp = [[[0] * 3 for _ in range(2)] for _ in range(n + 1)]
        # dp[0] = [[1, 1, 1], [1, 1, 1]]

        # dp[i][][] only depends on dp[i - 1][][], can have
        # state compression to optimize space usage
        dp = [[1, 1, 1], [1, 1, 1]]
        for i in range(1, n + 1):
            pre = dp
            dp = [[0, 0, 0], [0, 0, 0]]
            for j in range(2):
                for k in range(3):
                    # seq[i] = P
                    # val = dp[i - 1][j][2]
                    val = pre[j][2]

                    # seq[i] = A
                    if j > 0:
                        # val = (val + dp[i - 1][j - 1][2]) % MOD
                        val = (val + pre[j - 1][2]) % self.MOD

                    # seq[i] = L
                    if k > 0:
                        # val = (val + dp[i - 1][j][k - 1]) % MOD
                        val = (val + pre[j][k - 1]) % self.MOD

                    # dp[i][j][k] = val
                    dp[j][k] = val

        # return dp[n][1][2]
        return dp[1][2]
    
    # Solution 2: exponentiating by squaring
    # T: O(log(n))
    # S: O(1)
    def checkRecord(self, n: int) -> int:
        """
        If we treat dp[i][][] and dp[i - 1][][] above as two sets of vectors,
        then dp[i][][] = A * dp[i - 1][][], where A is
        [[0, 0, 1, 0, 0, 0],
         [1, 0, 1, 0, 0, 0],
         [0, 1, 1, 0, 0, 0],
         [0, 0, 1, 0, 0, 1],
         [0, 0, 1, 1, 0, 1],
         [0, 0, 1, 0, 1, 1]]

        Thus, dp[n][][] = A ^ n * dp[0][][].
        The final answer is f[n][1][2], which involves multiplying the last row 
        of A ^ n and the column vector `[1 1 1 1 1 1].T`. Interestingly, it is also 
        equal to A^(n+1)[5][2] as the third column of A is just that vector.
        """

        def mul(mat1: List[List[int]], mat2: List[List[int]]) -> List[List[int]]:
            M = len(mat1)
            res = [[0] * M for _ in range(M)]
            for i in range(M):
                for j in range(M):
                    for k in range(M):
                        res[i][j] = (res[i][j] + mat1[i][k] * mat2[k][j]) % self.MOD
            return res

        def pow(mat: List[List[int]], n: int) -> List[List[int]]:
            M = len(mat)
            res = [[0] * M for _ in range(M)]
            for i in range(M):
                res[i][i] = 1
            while n > 0:
                if n & 1:
                    res = mul(res, mat)
                mat = mul(mat, mat)
                n >>= 1
            return res

        A = [[0, 0, 1, 0, 0, 0],
             [1, 0, 1, 0, 0, 0],
             [0, 1, 1, 0, 0, 0],
             [0, 0, 1, 0, 0, 1],
             [0, 0, 1, 1, 0, 1],
             [0, 0, 1, 0, 1, 1]]
        return pow(A, n + 1)[5][2]

# @lc code=end

