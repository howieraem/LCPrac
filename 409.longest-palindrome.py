#
# @lc app=leetcode id=409 lang=python3
#
# [409] Longest Palindrome
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(alpha_size)
    def longestPalindrome(self, s: str) -> int:
        cnts = [0] * 52
        OFFSET_L = ord('a') - 26
        OFFSET_U = ord('A')
        for c in s:
            if c > 'Z':  # ord('a') > ord('Z')
                cnts[ord(c) - OFFSET_L] += 1
            else:
                cnts[ord(c) - OFFSET_U] += 1
        
        ans = 0

        for cnt in cnts:
            # if cnt is even, can use all
            # otherwise, can use an even count of char by minus 1
            ans += cnt - (cnt & 1)

        # if all cnts are even, ans = len(s)
        # otherwise, we can have one odd char in the middle, so add 1 to ans
        return ans + 1 if ans < len(s) else ans

# @lc code=end

