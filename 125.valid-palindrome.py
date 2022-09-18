#
# @lc app=leetcode id=125 lang=python3
#
# [125] Valid Palindrome
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def isPalindrome(self, s: str) -> bool:
        i = 0
        j = len(s) - 1

        while i < j:
            c1, c2 = s[i], s[j]
            if not c1.isalnum():
                i += 1
            elif not c2.isalnum():
                j -= 1
            else:
                if c1.lower() != c2.lower():
                    return False
                i += 1
                j -= 1
        return True

# @lc code=end

