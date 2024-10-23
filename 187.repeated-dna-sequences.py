#
# @lc app=leetcode id=187 lang=python3
#
# [187] Repeated DNA Sequences
#
from typing import List

# @lc code=start
CHARS = {
    'A': 0,
    'C': 1,
    'G': 2,
    'T': 3
}
A = len(CHARS)

class Solution:
    # Rabin-Karp Algorithm (rolling hash): works well for a very large sequence length, 
    # a small alphabet size (< 5) and a small fixed window size (< 30)
    # T: O(n * L), n := len(s), L = 10
    # S: O(n)
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        L = 10
        N = len(s)
        if N <= L:
            return []
        
        POW = A ** (L - 1)
        encoded = [CHARS[c] for c in s]

        seen = set()    # appear more than zero times
        res = set()     # appear more than once

        # init hash for the first sequence of length L
        h = 0
        for i in range(L):
            h += encoded[i] * (A ** (L - 1 - i))
        seen.add(h)

        # sliding window
        for i in range(1, N - (L - 1)):
            h -= encoded[i - 1] * POW
            h *= A
            h += encoded[i + L - 1]

            if h in seen:
                res.add(s[i:i + L])
            else:
                seen.add(h)

        return list(res)


# @lc code=end

