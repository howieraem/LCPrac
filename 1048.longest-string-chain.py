#
# @lc app=leetcode id=1048 lang=python3
#
# [1048] Longest String Chain
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n * (log(n) + l)), n := len(words), l := max word length
    # S: O(n)
    def longestStrChain(self, words: List[str]) -> int:
        # Sort words by length, so that shorter words which could possible be
        # the predecessors will be added to dp dict before longer words.
        words.sort(key=lambda w: len(w))

        dp = dict()
        ans = 0
        for w in words:
            dp[w] = 1
            for i in range(len(w)):
                predecessor = w[:i] + w[i + 1:]
                if predecessor in dp:
                    dp[w] = max(dp[w], dp[predecessor] + 1)
            ans = max(ans, dp[w])
        return ans

# @lc code=end

