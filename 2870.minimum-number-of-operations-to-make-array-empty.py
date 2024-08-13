from collections import defaultdict
from typing import List

class Solution:
    # T: O(n)
    # S: O(n)
    def minOperations(self, nums: List[int]) -> int:
        counts = defaultdict(int)
        for x in nums:
            counts[x] += 1

        ans = 0
        for x, count in counts.items():
            if count == 1:
                return -1
            elim, mod = divmod(count, 3)
            ans += elim
            ans += (mod != 0)  # for count like 4, 7, etc.

        return ans
