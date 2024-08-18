from typing import List

class Solution:
    # T: O(len(s) * len(queries))
    # S: O(len(s))
    def countKConstraintSubstrings(self, s: str, k: int, queries: List[List[int]]) -> List[int]:
        n = len(s)

        r2l = [0] * n
        l = 0
        counts = [0, 0]
        for r in range(n):
            counts[int(s[r])] += 1
            while counts[0] > k and counts[1] > k:
                counts[int(s[l])] -= 1
                l += 1
            r2l[r] = l

        l2r = [0] * n
        r = n - 1
        counts = [0, 0]
        for l in range(n - 1, -1, -1):
            counts[int(s[l])] += 1
            while counts[0] > k and counts[1] > k:
                counts[int(s[r])] -= 1
                r -= 1
            l2r[l] = r
        
        prefix_sums = [0] * (n + 1)
        for r, l in enumerate(r2l):
            count = r - l + 1
            prefix_sums[r + 1] = prefix_sums[r] + count
        
        # For the right indexes that has left within the query bounds, all the substrings count
        # For the right indexes that has left outside the query bounds, only substrings within the bounds will count
        # So, separate the cases for each query
        res = []
        for l, r in queries:
            m = min(r, l2r[l])
            length = m - l + 1
            # where left is within, so all the substrings count
            ans = ((length * (length + 1)) >> 1) + prefix_sums[r + 1] - prefix_sums[m + 1]
            res.append(ans)
        return res
