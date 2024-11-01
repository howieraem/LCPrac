#
# @lc app=leetcode id=2131 lang=python3
#
# [2131] Longest Palindrome by Concatenating Two Letter Words
#
from collections import defaultdict
from typing import List

# @lc code=start
class Solution:
    '''
    # Solution 1: hash map + two pointer
    # T: O(n)
    # S: O(n)
    def longestPalindrome(self, words: List[str]) -> int:
        cnts = defaultdict(int)
        for w in words:
            cnts[w] += 1

        has_special_center = False
        ans = 0   # half of the length

        for w, cnt in cnts.items():
            if w[0] == w[1]:   # len(w) = 2, e.g., 'aa'
                if cnt & 1:
                    ans += cnt - 1
                    has_special_center = True
                else:
                    ans += cnt
            elif w[0] < w[1]:
                # pair patterns, like 'ab' with 'ba'
                ans += (min(cnt, cnts.get(w[::-1], 0)) << 1)
        
        if has_special_center:
            # For patterns like 'aa', if there are multiple of them with odd count,
            # we can only use one of them
            ans += 1

        return ans << 1
    '''

    # Solution 2: array + two pointer
    # T: O(n + alpha_size)
    # S: O(alpha_size ^ 2)
    def longestPalindrome(self, words: List[str]) -> int:
        OFFSET = ord('a')
        cnts = [[0] * 26 for _ in range(26)]
        ans = 0
        for w in words:
            a = ord(w[0]) - OFFSET
            b = ord(w[1]) - OFFSET
            if cnts[b][a] > 0:
                ans += 4
                cnts[b][a] -= 1
            else:
                cnts[a][b] += 1

        for i in range(26):
            if cnts[i][i] > 0:
                ans += 2
                break
        
        return ans


# @lc code=end

