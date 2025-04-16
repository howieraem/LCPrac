#
# @lc app=leetcode id=171 lang=python3
#
# [171] Excel Sheet Column Number
#

# @lc code=start
OFFSET = ord('A')

class Solution:
    # Math
    # T: O(n)
    # S: O(1)
    def titleToNumber(self, columnTitle: str) -> int:
        ans = 0
        for c in columnTitle:
            ans *= 26
            ans += ord(c) - OFFSET + 1
        return ans

# @lc code=end

