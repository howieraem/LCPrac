#
# @lc app=leetcode id=1208 lang=python3
#
# [1208] Get Equal Substrings Within Budget
#

# @lc code=start
class Solution:
    # Sliding window
    # T: O(n)
    # S: O(1)
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        ans = 0
        window_cost = 0
        l = 0
        for r in range(len(s)):
            window_cost += abs(ord(t[r]) - ord(s[r]))
            while window_cost > maxCost:
                window_cost -= abs(ord(t[l]) - ord(s[l]))
                l += 1
            ans = max(ans, r - l + 1)

        return ans

# @lc code=end

