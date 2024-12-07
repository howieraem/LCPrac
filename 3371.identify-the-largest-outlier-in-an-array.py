from collections import defaultdict
from typing import *

class Solution:
    # Math + hash map
    # T: O(n)
    # S: O(n)
    def getLargestOutlier(self, nums: List[int]) -> int:
        freqs = defaultdict(int)
        tot = 0
        for x in nums:
            tot += x
            freqs[x] += 1
        
        ans = float('-inf')
        for x in nums:
            # cand = tot - sum_cand - sum_of_rest
            cand = tot - (x << 1)

            # case 1: freqs[cand] = 1, cand != x
            # case 2: freqs[cand] > 1, cand = x, i.e. cand has duplicates and one of them must be an outlier
            if freqs.get(cand, 0) > int(cand == x):
                ans = max(ans, cand)
        
        return ans
