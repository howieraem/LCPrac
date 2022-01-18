class Solution:
    def numWays(self, n: int) -> int:
        # very similar to fib, except fib(0) = 1
        if n < 2:
            return 1
        i2, i1, i = 1, 1, 0
        while n >= 2:
            # mod here is equivalent to mod once at the end,
            # but avoids overflow in C++, Java, etc.
            # 
            # Proof:
            # (x + y) % d = (x % d + y % d) % d
            # Thus,
            # fib(n) % d = (fib(n - 1) % d + fib(n - 2) % d) % d
            i = (i2 + i1) % 1000000007

            i2 = i1
            i1 = i
            n -= 1
        return i
