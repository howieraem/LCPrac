from typing import List

class Solution:
    # Binary search
    # T: O(n * (log(n) + log(max_diff)))
    # S: O(n) sorting
    def maxPossibleScore(self, start: List[int], d: int) -> int:
        start.sort()
        n = len(start)

        def is_possible(start, x):
            prev = start[0]
            # test if the abs diff is feasible for all start
            for i in range(1, n):
                candidate = max(prev + x, start[i])
                if candidate > start[i] + d:
                    return False
                prev = candidate
            return True

        l = 0

        # Max possible difference between the first and last interval
        r = (start[-1] + d) - start[0]

        ans = 0
        
        while l <= r:
            m = l + ((r - l) >> 1)
            if is_possible(start, m):
                ans = m
                l = m + 1
            else:
                r = m - 1
        
        return ans
