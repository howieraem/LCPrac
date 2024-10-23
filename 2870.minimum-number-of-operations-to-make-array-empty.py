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
                # Impossible to eliminate single element
                return -1

            # Greedy: eliminate elements with count = multiples of 3
            elim, mod = divmod(count, 3)
            ans += elim

            # For count like 4, 7, etc., the number of eliminations 
            # is just 1 more than count // 3.
            # 4 = 2 + 2
            # 7 = 2 + 2 + 3
            ans += (mod != 0)

            # Combine both cases above: ans += ceil(count / 3.0)

        return ans
