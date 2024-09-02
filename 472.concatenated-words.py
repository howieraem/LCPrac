#
# @lc app=leetcode id=472 lang=python3
#
# [472] Concatenated Words
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n * l ^ 3), n := len(words), l := max(len(w) for w in words)
    # S: O(n + l)
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        words.sort(key=lambda x: len(x))
        word_set = set()

        res = []

        for w in words:
            l = len(w)
            if l == 0:
                continue

            # dp[i] means if word[0...i] is a concat word
            dp = [False] * (l + 1)
            dp[0] = True

            for i in range(1, l + 1):
                for j in range(i, -1, -1):  # words sorted by length ASC
                    if dp[j] and w[j:i] in word_set:
                        dp[i] = True
                        break

            if dp[l]:
                res.append(w)

            word_set.add(w)

        return res


# @lc code=end

