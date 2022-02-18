#
# @lc app=leetcode id=567 lang=python3
#
# [567] Permutation in String
#
from collections import defaultdict

# @lc code=start
class Solution:
    # T: O(n + s), n := len(s2), s := alpha size
    # S: O(s)
    def checkInclusion(self, s1: str, s2: str) -> bool:
        k = len(s1)
        n = len(s2)
        if k > n:
            return False

        freq = defaultdict(int)
        for c in s1:
            freq[c] += 1

        for r in range(n):
            l = r - k
            if s2[r] in freq:
                freq[s2[r]] -= 1
            if l >= 0 and s2[l] in freq:
                freq[s2[l]] += 1

            if all(v == 0 for v in freq.values()):
                return True

        return False


# @lc code=end

