#
# @lc app=leetcode id=2083 lang=python3
#
# [2083] Substrings That Begin and End With the Same Letter
#
from collections import defaultdict

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n)
    def numberOfSubstrings(self, s: str) -> int:
        ans = 0
        cnts = defaultdict(int)

        # When visiting a character c, the number of substrings 
        # that begin and end with c in the prefix substring is 
        # the frequency of c in this prefix substring + 1
        for c in s:
            cnts[c] += 1
            ans += cnts[c]
        
        return ans

        # One may notice the number of substrings that begin and end with c 
        # actually equal to the sum of an arithmetic progression 1, 2, 3, ...
        # Therefore: 
        # ans = sum(n * ((n + 1) >> 1) for n in Counter(s).values())
        # Same complexities, but less hash function computations

# @lc code=end

