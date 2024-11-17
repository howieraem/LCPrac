from collections import defaultdict
from typing import *

class Solution:
    # hash map
    # T: O(n)
    # S: O(n)
    def numIdenticalPairs(self, nums: List[int]) -> int:
        ans = 0
        freqs = defaultdict(int)
        for x in nums:
            ans += freqs[x]
            freqs[x] += 1
        return ans
