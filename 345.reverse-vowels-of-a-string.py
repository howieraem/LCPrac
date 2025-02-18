#
# @lc app=leetcode id=345 lang=python3
#
# [345] Reverse Vowels of a String
#

# @lc code=start
class Solution:
    # Two pointers
    # T: O(n)
    # S: O(n) if string immutable
    def reverseVowels(self, s: str) -> str:
        s = list(s)
        VOWELS = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'}

        l = 0
        r = len(s) - 1

        while l < r:
            is_vowel_l = s[l] in VOWELS
            is_vowel_r = s[r] in VOWELS
            if is_vowel_l and is_vowel_r:            
                s[l], s[r] = s[r], s[l]
                l += 1
                r -= 1
            elif not is_vowel_l:
                l += 1
            elif not is_vowel_r:
                r -= 1

        return ''.join(s)
        
# @lc code=end

