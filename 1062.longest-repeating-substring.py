#
# @lc app=leetcode id=1062 lang=python3
#
# [1062] Longest Repeating Substring
#

# @lc code=start
class Solution:
    # T: O(n ^ 2)
    # S: O(n)
    def longestRepeatingSubstring(self, s: str) -> int:
        n = len(s)
        ans = 0

        # dp[i][j] means the max. len. of common substring of s[:i+1] and s[:j+1]
        # dp = [[0] * (n + 1) for _ in range(n + 1)]
        dp = [0] * (n + 1)  # optimized space
        for i in range(1, n + 1):
            for j in range(i - 1, 0, -1):
                if s[i - 1] == s[j - 1]:
                    # dp[i][j] = dp[i - 1][j - 1] + 1
                    # ans = max(ans, dp[i][j])
                    
                    # optimized space
                    dp[j] = dp[j - 1] + 1
                    ans = max(ans, dp[j])
                else:
                    dp[j] = 0
        return ans
        
# @lc code=end

