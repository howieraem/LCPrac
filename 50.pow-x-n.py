#
# @lc app=leetcode.cn id=50 lang=python3
#
# [50] Pow(x, n)
#

# @lc code=start
class Solution:
    def myPow(self, x: float, n: int) -> float:
        """
        快速幂
        
        思想：
            1. 把幂转为二进制: n = 2^(2*i0) + 2^(2*i1) + ... + 2^(2*ik)，其中一些i是0。
            2. x^n = x^(2^(2*i0)) + x^(2^(2*i1)) + ... + x^(2^(2*ik))
        """
        return self.quickMul(x, n) if n >= 0 else 1.0 / self.quickMul(x, -n)

    @staticmethod
    def quickMul(x, n):
        ans = 1.0
        # 贡献的初始值为 x
        x_contribute = x
        # 在对 N 进行二进制拆分的同时计算答案
        while n > 0:
            n, remain = divmod(n, 2)    # 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
            if remain:
                # 如果 N 二进制表示的最低位为 1，那么需要计入贡献
                ans *= x_contribute
            # 将贡献不断地平方
            x_contribute *= x_contribute
        return ans

# @lc code=end
s = Solution()
print(s.myPow(2.0, 2**31-1))
