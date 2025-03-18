from collections import defaultdict
from typing import List

class Solution:
    # Math + Sorting + Greedy
    def maxIncreasingGroups(self, usageLimits: List[int]) -> int:
        # We need at least 1 + 2 + ... + k = k * (k + 1) / 2 elements to form k groups.
        # We can try allocating elements as follows:
        # - Use elements with higher limit first
        # - Use elements with lower limit last
        # Therefore, we should sort usageLimits first.
        # Then, iteratively see if we can increment and thus maximize k
        # by checking (k + 1) * (k + 2) / 2.

        '''
        # Solution 1: built-in sorting
        # T: O(n * log(n))
        # S: O(n) timsort
        usageLimits.sort()
        tot = 0
        k = 0
        for limit in usageLimits:
            tot += limit
            if tot >= (((k + 1) * (k + 2)) >> 1):
                k += 1
        return k
        '''

        # Solution 2: counting sort
        # T: O(n) amortised
        # S: O(n)
        n = len(usageLimits)
        cnts = defaultdict(int)
        for limit in usageLimits:
            cnts[min(limit, n)] += 1
        
        tot = 0
        k = 0
        last_tot = 1
        for i in range(n + 1):
            for _ in range(cnts[i]):
                tot += i
                if tot >= last_tot:
                    k += 1
                    last_tot = ((k + 1) * (k + 2)) >> 1
        return k
