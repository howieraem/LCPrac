#
# @lc app=leetcode id=139 lang=python3
#
# [139] Word Break
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n ^ 3) (because s[i:j] is O(n))
    # S: O(n + l), l := len(wordDict)
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordDict = set(wordDict)
        n = len(s)

        # dp[i] means whether s[:i+1] can be segmented into words in wordDict. 
        # Add one for the case empty string which should be true.
        dp = [False] * (n + 1)
        dp[0] = True

        # Approach 1
        # for i in range(n):
        #     for j in range(i+1, n+1):
        #         if dp[i] and s[i:j] in wordDict:
        #             dp[j] = True

        # Approach 2, less iterations than approach 1, example:
        # leetcode
        # -
        #
        # leetcode
        #  -
        # --
        #
        # leetcode
        #   -
        #  --
        # ---
        #
        # leetcode
        #    -
        #   --
        #  ---
        # ----     !!! leet
        #
        # leetcode
        #     -
        #    --
        #   ---
        #  ----
        # -----
        #
        # leetcode
        #      -
        #     --
        #    ---
        #   ----
        #  -----
        # ------
        #
        # leetcode
        #       -
        #      --
        #     ---
        #    ----
        #   -----
        #  ------
        # -------
        #
        # leetcode
        #        -
        #       --
        #      --- 
        #     ----  !!! code
        # (BREAK HERE)
        for i in range(1, n + 1):
            for j in range(i - 1, -1, -1):
                if dp[j] and s[j:i] in wordDict:
                    dp[i] = True
                    break

        return dp[n]

# @lc code=end

