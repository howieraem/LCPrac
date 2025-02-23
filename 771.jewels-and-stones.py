#
# @lc app=leetcode id=771 lang=python3
#
# [771] Jewels and Stones
#

# @lc code=start
class Solution:
    # Hash map
    # T: O(m + n)
    # S: O(m)
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        jewels = set(jewels)
        ans = 0
        for c in stones:
            ans += c in jewels
        return ans

        
# @lc code=end

