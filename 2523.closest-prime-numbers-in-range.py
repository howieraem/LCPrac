import math
from typing import List

class Solution:
    # Sieve of Eratosthenes
    # T: O(right * log(log(right)))
    # S: O(right)
    def closestPrimes(self, left: int, right: int) -> List[int]:
        primes = self.sieve(left, right)
        res = [-1, -1]
        if len(primes) < 2:
            return res
        min_diff = math.inf
        for i in range(len(primes) - 1):
            diff = primes[i + 1] - primes[i]
            if diff < min_diff:
                res = [primes[i], primes[i + 1]]
                min_diff = diff
        return res

    def sieve(self, l: int, r: int) -> List[int]:
        prime = [True] * (r + 1)
        prime[0] = prime[1] = False

        upper = int(math.sqrt(r)) + 1 
        for i in range(2, upper):
            if prime[i]:
                sq = i * i
                for j in range(sq, r + 1, i):
                    prime[j] = False

        return [i for i in range(l, r + 1) if prime[i]]
