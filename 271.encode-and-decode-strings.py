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
        res = []
        for s in strs:
            res.append(str(len(s)))
            res.append('/')
            res.append(s)
        return "".join(res)
    
    # T: O(n)
    # S: O(n)
    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings.
        """
        res = []
        i = 0
        while i < len(s):
            j = i
            while j < len(s) and s[j] != '/':
                j += 1
            sz = int(s[i:j])  # decode the cur word size
            i = j + sz + 1  # update i to the end of cur word
            res.append(s[j + 1:i])  # decode the cur word
        return res
# @lc code=end

