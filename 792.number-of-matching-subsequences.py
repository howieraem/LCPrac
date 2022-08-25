#
# @lc app=leetcode id=792 lang=python3
#
# [792] Number of Matching Subsequences
#
from collections import defaultdict
from typing import List

# @lc code=start
class Solution:
    # T: O(m * n * l), m := len(s), n := len(words), l := max. word length of words
    # S: O(n * l)
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        words_start_with_char = defaultdict(list)
        for w in words:
            words_start_with_char[w[0]].append(w)

        ans = 0
        for c in s:
            w_candidates = words_start_with_char[c]
            if not len(w_candidates):
                continue
            words_start_with_char[c] = []
            for w in w_candidates:
                if len(w) == 1:
                    # Candidate word reduced to a single char,
                    # a subseq is found
                    ans += 1
                else:
                    words_start_with_char[w[1]].append(w[1:])
        return ans

# @lc code=end

