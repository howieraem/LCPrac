#
# @lc app=leetcode id=1456 lang=python3
#
# [1456] Maximum Number of Vowels in a Substring of Given Length
#

# @lc code=start
class Solution:
    # sliding window
    # T: O(n)
    # S: O(vowel_size)
    def maxVowels(self, s: str, k: int) -> int:
        VOWELS = {'a', 'e', 'i', 'o', 'u'}
        ans = 0
        window_vowel_cnt = 0
        for r in range(len(s)):
            window_vowel_cnt += (s[r] in VOWELS)

            if r == k - 1:
                ans = max(ans, window_vowel_cnt)
            
            if r >= k:
                l = r - k
                window_vowel_cnt -= (s[l] in VOWELS)
                ans = max(ans, window_vowel_cnt)

        return ans

# @lc code=end

