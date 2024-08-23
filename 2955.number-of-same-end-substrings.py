from typing import *

class Solution:
    # T: O(alpha_size * (len(s) + len(queries)))
    # S: O(alpha_size * len(s))
    def sameEndSubstringCount(self, s: str, queries: List[List[int]]) -> List[int]:
        freqs = [0] * 26
        prefix_freqs = [freqs[:]]
        OFFSET = ord('a')
        for c in s:
            # IMPORTANT: make a copy to ensure prefix freq
            freqs[ord(c) - OFFSET] += 1
            prefix_freqs.append(freqs[:])
        
        res = [0] * len(queries)
        for i, (l, r) in enumerate(queries):
            ans = 0
            for ci in range(26):
                # count of s[l...r] = count of s[0...r] - count of s[0...l)
                freq = prefix_freqs[r + 1][ci] - prefix_freqs[l][ci]

                # nCr + n, n := freq, r := 2
                # (n * (n - 1)) // 2 + n = (n * (n + 1)) // 2
                ans += ((freq * (freq + 1)) >> 1)
            res[i] = ans

        return res
