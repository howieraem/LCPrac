#
# @lc app=leetcode id=1234 lang=python3
#
# [1234] Replace the Substring for Balanced String
#
from collections import defaultdict

# @lc code=start
class Solution:
    # Hash Map + Sliding window
    # T: O(n)
    # S: O(alpha_sz)
    def balancedString(self, s: str) -> int:
        n = len(s)
        k = (n >> 2)  # n // 4
        cnts = defaultdict(int)  # out-of-window counts
        TARGET_CHARS = 'QWER'

        for c in s:
            cnts[c] += 1

        ans = n
        l = 0
        for r in range(n):
            cnts[s[r]] -= 1

            while l < n and all(cnts[c] <= k for c in TARGET_CHARS):
                # As long as any of the counts outside the window is not enough,
                # we know the chars excl. the current window are unbalanced,
                # and thus the current window is a substring to be replaced.
                ans = min(ans, r - l + 1)
                cnts[s[l]] += 1
                l += 1

        return ans


# @lc code=end

