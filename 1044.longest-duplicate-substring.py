#
# @lc app=leetcode id=1044 lang=python3
#
# [1044] Longest Duplicate Substring
#
from collections import defaultdict

# @lc code=start
class Solution:
    # Rabin-Karp + Sliding Window + Binary Search
    # T: O(n * log(n))
    # S: O(n)
    def longestDupSubstring(self, s: str) -> str:
        MOD = (1 << 61) - 1   # a large prime number to avoid collision
        BASE = 26
        OFFSET = ord('a')

        def find_len_k_duplicate_substr(k):
            D = pow(BASE, k - 1, MOD)  # (BASE ** (k - 1)) % MOD
            substr_idxs = defaultdict(list)   # k: window_hash, v: list of substr end indices

            # Rolling hash with size-k sliding window
            window_hash = 0
            for r in range(len(s)):
                if r >= k:
                    l_cidx = ord(s[r - k]) - OFFSET
                    window_hash = (window_hash - l_cidx * D) % MOD

                cidx = ord(s[r]) - OFFSET
                window_hash = (window_hash * BASE + cidx) % MOD

                if r >= k - 1:
                    idxs = substr_idxs.get(window_hash, [])
                    if len(idxs) > 0:
                        cur_substr = s[r - k + 1:r + 1]
                        for r2 in idxs:
                            # Check if it's a valid duplicate substr,
                            # or actually a hash collision
                            if cur_substr == s[r2 - k + 1:r2 + 1]:
                                return cur_substr
                
                    substr_idxs[window_hash].append(r)
            
            return ''  # no valid substr of len k found

        
        l = 1   # minimum length of substr (we ignore empty str)
        r = len(s)   # maximum length of substr
        res = ''

        while l < r:
            m = l + ((r - l) >> 1)
            substr = find_len_k_duplicate_substr(m)
            if substr != '':
                res = substr
                l = m + 1
            else:
                r = m
    
        return res

# @lc code=end

