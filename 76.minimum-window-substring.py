#
# @lc app=leetcode id=76 lang=python3
#
# [76] Minimum Window Substring
#
from collections import defaultdict

# @lc code=start
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        freq = defaultdict(int)
        for c in t:
            freq[c] += 1
        
        ans_begin = 0
        ans_len = 100001  # inf
        cur_freq = 0

        l = 0
        for r in range(len(s)):
            if freq[s[r]] > 0:
                cur_freq += 1
            freq[s[r]] -= 1
            
            while cur_freq == len(t):
                # Found a substring, update result 
                # and try shrinking it
                cur_len = r - l + 1
                if cur_len < ans_len:
                    ans_len = cur_len
                    ans_begin = l

                freq[s[l]] += 1
                if freq[s[l]] > 0:
                    cur_freq -= 1
                l += 1

        return s[ans_begin:ans_begin + ans_len] if ans_len != 100001 else ""

# @lc code=end

