class Solution:
    def cuttingRope(self, n: int) -> int:
        '''
        # 数学法
        # 1. 若拆分的数量确定，则各拆分数字相等时，乘积最大
        # 2. 将数字尽可能以因子 3 等分时，乘积最大
        # 关于为什么切分为3的优先级最高: 
        # 可以利用均值不等式求出乘积最大值 L(m)=(n/m)^m 对此式求导（可利用对数法），
        # 可以证明当 m=n/e 时，乘积取最大，此时每段绳子的长度为 n/(n/e)=e，
        # 自然对数e的值为2.718，显然接近3，所以总体来讲3最好
        if n <= 3:
            return n - 1
        a, b = n // 3, n % 3
        if b == 0:
            return int(math.pow(3, a))
        elif b == 1:
            return int(math.pow(3, a - 1)) * 4
        else:
            return int(math.pow(3, a)) * 2
        '''

        # 动态规划法（可能溢出）
        dp = [0] * (n + 1)
        for i in range(2, n + 1):   # start from 2 as 1 does not contribute to larger product
            for j in range(i):
                dp[i] = max(dp[i], j * (i - j), j * dp[i - j])
        return dp[n]
