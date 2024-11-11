#
# @lc app=leetcode id=935 lang=python3
#
# [935] Knight Dialer
#

# @lc code=start
import numpy as np

class Solution:
    # T: O(log(n))
    # S: O(1) as matrix size is fixed
    def knightDialer(self, n: int) -> int:
        if n == 1:
            return 10
        F = 1000000007

        # A[i][j] is 1 if j is a valid neighbor of i, 0 otherwise.
        A = np.array([[0, 0, 0, 0, 1, 0, 1, 0, 0, 0],
                      [0, 0, 0, 0, 0, 0, 1, 0, 1, 0],
                      [0, 0, 0, 0, 0, 0, 0, 1, 0, 1],
                      [0, 0, 0, 0, 1, 0, 0, 0, 1, 0],
                      [1, 0, 0, 1, 0, 0, 0, 0, 0, 1],
                      [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                      [1, 1, 0, 0, 0, 0, 0, 1, 0, 0],
                      [0, 0, 1, 0, 0, 0, 1, 0, 0, 0],
                      [0, 1, 0, 1, 0, 0, 0, 0, 0, 0],
                      [0, 0, 1, 0, 1, 0, 0, 0, 0, 0]], dtype=np.int64)

        res = np.eye(10, dtype=np.int64)
        n -= 1
        while n != 0:
            if n & 1:  # n is odd
                res = (res % F @ A % F) % F
            A %= F
            A = (A @ A) % F
            n >>= 1
        ans = 0
        for i in range(10):
            for j in range(10):
                ans = (ans % F + res[i][j] % F) % F
        return ans


# @lc code=end
