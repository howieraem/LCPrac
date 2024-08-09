#
# @lc app=leetcode id=1461 lang=python3
#
# [1461] Check If a String Contains All Binary Codes of Size K
#

# @lc code=start
class Solution:
    # T: O(min(len(s) * k, 2 ** k))
    # S: O(min(len(s) * k, 2 ** k))
    def hasAllCodes(self, s: str, k: int) -> bool:
        # Do a simple sliding window to store all substrings with length k
        substrs = set()
        total = (1 << k)  # With k bits, there are 2^k binary numbers
        for i in range(len(s) - k + 1):
            substrs.add(s[i:i + k])
            if len(substrs) == total:
                return True
        
        return False

# @lc code=end

