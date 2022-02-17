#
# @lc app=leetcode id=953 lang=python3
#
# [953] Verifying an Alien Dictionary
#
from typing import List

# @lc code=start
class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        mapping = {c: i for i, c in enumerate(order)}

        n = len(words)
        # new_words = [""] * n

        # Initialized to (0, ) to compare with 
        # the first rearranged word (i == 0)
        pre = (0, )
        for i in range(n):
            # Tuple of character indexes is enough for checking,
            # no need to convert to a string
            w = tuple([mapping[c] for c in list(words[i])])

            # new_words[i] = w
            if pre > w:
                return False
            pre = w
        return True

# @lc code=end

