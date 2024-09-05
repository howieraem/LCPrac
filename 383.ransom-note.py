#
# @lc app=leetcode id=383 lang=python3
#
# [383] Ransom Note
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(alpha_size)
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        cnts = [0] * 26
        OFFSET = ord('a')
        for c in magazine:
            cnts[ord(c) - OFFSET] += 1
        for c in ransomNote:
            cnts[ord(c) - OFFSET] -= 1
            if cnts[ord(c) - OFFSET] < 0:
                return False
        return True

# @lc code=end

