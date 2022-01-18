class Solution:
    def cuttingRope(self, n: int) -> int:
        if n <= 3:
            return n - 1

        '''
        # 数学法
        a, b, p, x, r = n // 3 - 1, n % 3, 1000000007, 3, 1

        # 快速幂求余
        # r = (x ** a) % p
        # 
        # Property of modulas arithmatic:
        # (a * b) % c = ((a % c) * (b % c)) % c 
        #
        # When a is even:
        # r = ((x * x) ** (a // 2)) % p
        #   = (((x * x) % p) ** (a // 2)) % p
        # When a is odd:
        # r = (x * ((x * x) % p) ** (a // 2)) % p
        while a > 0:
            # if a % 2 == 1:
            if a & 1:   
                r = (r * x) % p
            x = (x * x) % p
            # a //= 2
            a >>= 1

        # Now r = (3 ** a) % p
        if b == 0:
            # return int(math.pow(3, a + 1)) % p
            return (r * 3) % p
        elif b == 1:
            # return int(math.pow(3, a) * 4) % p
            return (r * 4) % p
        else:
            # return int(math.pow(3, a + 1) * 2) % p
            return (r * 6) % p
        '''

        # 贪心
        if n == 4:
            return 4
        p, ans = 1000000007, 1
        while n > 4:
            ans = (ans * 3) % p
            n -= 3
        return (ans * n) % p
