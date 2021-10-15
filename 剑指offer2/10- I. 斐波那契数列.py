class Solution:
    def fib(self, n: int) -> int:
        if n < 2:
            return n
        i2, i1, i = 0, 1, 0
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
