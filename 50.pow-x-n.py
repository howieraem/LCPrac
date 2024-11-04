#
# @lc app=leetcode id=50 lang=python3
#
# [50] Pow(x, n)
#

# @lc code=start
# Exponentiation by squaring
class Solution:
    '''
    # Solution 1: recursive
    # T: O(log(n))
    # S: O(log(n))
    def myPow(self, x: float, n: int) -> float:
        if not n:
            return 1
        if n < 0:
            n *= -1
            x = 1 / x
            # Or the following to avoid overflow in other languages:
            # return 1 / x * myPow(1 / x, -(n + 1))

        # Check if n is odd and recur accordingly
        return x * self.myPow(x * x, n >> 1) if (n & 1) else self.myPow(x * x, n >> 1)
    '''

    # Solution 2: iterative
    # T: O(log(n))
    # S: O(1)
    def myPow(self, x: float, n: int) -> float:
        return self.helper(x, n) if n >= 0 else 1. / self.helper(x, -n)

    @staticmethod
    def helper(x, n):
        ans = 1.
        while n > 0:
            if (n & 1) != 0:
                ans *= x
            x *= x
            n >>= 1
        return ans

# @lc code=end

