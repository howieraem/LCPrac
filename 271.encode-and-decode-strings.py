#
# @lc app=leetcode id=271 lang=python3
#
# [271] Encode and Decode Strings
#
from typing import *

# @lc code=start
class Codec:
    # T: O(n)
    # S: O(n)
    def encode(self, strs: List[str]) -> str:
        """Encodes a list of strings to a single string.
        """
        # individual words and corresponding sizes
        res = []
        for s in strs:
            res.append(str(len(s)))
            res.append('/')
            res.append(s)
        return "".join(res)
    
    # two pointers
    # T: O(n)
    # S: O(n)
    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings.
        """
        res = []
        i = 0
        while i < len(s):
            j = i + 1
            while j < len(s) and s[j] != '/':
                j += 1
            sz = int(s[i:j])        # decode the cur word size
            i = j + 1 + sz          # move i to the end of cur word
            # now s[j] = '/', s[j + 1] is the first char of cur word, decode the cur word
            res.append(s[j + 1:i])
        return res
# @lc code=end

