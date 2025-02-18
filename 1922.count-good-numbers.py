#
# @lc app=leetcode id=1922 lang=python3
#
# [1922] Count Good Numbers
#

# @lc code=start
class Solution:
    # Math + Combination + Power
    # T: O(log(n))
    # S: O(1)
    def countGoodNumbers(self, n: int) -> int:
        MOD = 1000000007
        
        # 4 primes {2, 3, 5, 7}, 5 even numbers {0, 2, 4, 6, 8}
        # n digits, n // 2 even indices, n - n // 2 odd indices
        # The number of good number is then 5 * 4 * 5 * ... = pow(5, n // 2) * pow(4, n - n // 2)
        pow_even = n >> 1
        pow_odd = n - pow_even

        # Modified from LC Q50
        def pow(x, n, mod):
            x %= mod
            if x == 0:
                return 0

            ans = 1

            while n > 0:
                if n & 1:
                    ans = (ans * x) % mod
                
                n >>= 1
                x = (x * x) % mod

            return ans
        
        return pow(4, pow_even, MOD) % MOD * pow(5, pow_odd, MOD) % MOD


# @lc code=end

