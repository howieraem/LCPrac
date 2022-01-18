class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n >= 0:
            return self.quickPow(x, n)
        return 1. / self.quickPow(x, -n)

    @staticmethod
    def quickPow(x, n):
        # 1. 把幂转为二进制: n = 2^(2*i0) + 2^(2*i1) + ... + 2^(2*ik)，其中一些i是0。
        # 2. x^n = x^(2^(2*i0)) + x^(2^(2*i1)) + ... + x^(2^(2*ik))
        ans = 1.
        x_contrib = x
        while n:
            if n & 1:
                ans *= x_contrib
            x_contrib *= x_contrib
            n >>= 1
        return ans
