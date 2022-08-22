#
# @lc app=leetcode id=843 lang=python3
#
# [843] Guess the Word
#
import random
from typing import List

class Master:
    def guess(self, word: str):
        pass

# @lc code=start
class Solution:
    # Reduce calling guess(w) as many as possible. Try to narrow the 
    # candidates after each time we call guess(w).
    # More explanations: https://leetcode.com/problems/guess-the-word/discuss/556075
    # T: O(n^2 * l), n := initial len(wordlist), l := word length
    # S: O(n)
    def findSecretWord(self, words: List[str], master: 'Master') -> None:
        N = len(words)
        L = len(words[0])  # 6
        i = 0
        matches = 0
        while i < N:
            candidate = words[random.randint(0, len(words) - 1)]
            prev_matches = matches
            matches = master.guess(candidate)
            if matches == L:
                break
            if matches > 0 and matches <= prev_matches:
                continue
            candidates = []
            for w in words:
                if matches == self.get_matches(candidate, w):
                    candidates.append(w)
            words = candidates
        return candidate

    @staticmethod
    def get_matches(w1, w2):
        cnt = 0
        for c1, c2 in zip(w1, w2):
            cnt += c1 == c2
        return cnt

# @lc code=end

