#
# @lc app=leetcode id=249 lang=python3
#
# [249] Group Shifted Strings
#
from collections import defaultdict
from typing import *

# @lc code=start
class Solution:
    # Hash map + customized hash function
    # T: O(n * w), w := word length
    # S: O(n * w)
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        res = defaultdict(list)

        # Hash each string based on pairwise char diffs
        def custom_hash(word: str) -> Tuple[int]:
            n = len(word)
            if n == 1:
                return 1
            
            diffs = [0] * (n - 1)
            for i in range(n - 1):
                diff = ord(word[i + 1]) - ord(word[i])
                if diff < 0:
                    # handle cases like a -> z or z -> a
                    diff += 26
                diffs[i] = diff
            return tuple(diffs)
        
        for w in strings:
            res[custom_hash(w)].append(w)

        return list(res.values())

        

# @lc code=end

