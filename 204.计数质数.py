#
# @lc app=leetcode.cn id=204 lang=python3
#
# [204] 计数质数
#
import math

# @lc code=start
class Solution:
    def countPrimes(self, n: int) -> int:
        # time complexity O(NloglogN)
        if n < 2:
            return 0
        is_primes = [True]*n
        is_primes[0] = False
        is_primes[1] = False

        for i in range(2, math.ceil(math.sqrt(n))):   # stop at sqrt(n), because x * y = y * x, whether x > y does not matter
            if is_primes[i]:
                # exclude multiples of current prime which are not primes
                for j in range(2*i, n, i):
                    is_primes[j] = False
        return sum(is_primes)

# @lc code=end

