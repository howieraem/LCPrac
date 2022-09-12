#
# @lc app=leetcode id=809 lang=python3
#
# [809] Expressive Words
#
from typing import *

# @lc code=start
class Solution:
    # T: O(n + sum(len(w) for w in words))
    # S: O(1)
    def expressiveWords(self, s: str, words: List[str]) -> int:
        n = len(s)
        ans = 0
        for w in words:
            m = len(w)
            if m > n:
                # too long to be stretchy
                continue
            
            # two pointer
            i = j = 0
            while i < m and j < n:
                if w[i] != s[j]:
                    break

                w_repeat = s_repeat = 1
                while i < m - 1 and w[i] == w[i + 1]:
                    w_repeat += 1
                    i += 1
                
                while j < n - 1 and s[j] == s[j + 1]:
                    s_repeat += 1
                    j += 1

                # Either w contains too many same chars, or the repeated char group size is less than 3.
                # IMPORTANT: Don't break if w_repeat == s_repeat
                if w_repeat > s_repeat or w_repeat < s_repeat < 3:
                    break

                i += 1
                j += 1
            
            # IMPORTANT: condition to check stretchy
            ans += (i == m and j == n)

        return ans

# @lc code=end

