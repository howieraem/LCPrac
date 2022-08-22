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
    # However, calling guess(w) less than 10 times is not strictly guaranteed.
    # More explanations: 
    #   - https://leetcode.com/problems/guess-the-word/discuss/556075
    #   - https://leetcode.com/problems/guess-the-word/discuss/134251
    # T: O(n^2 * l), n := initial len(wordlist), l := word length
    # S: O(n)
    def findSecretWord(self, words: List[str], master: 'Master') -> None:
        L = len(words[0])  # 6
        matches = 0
        while True:
            # Approach 1: random guess (more likely to fail some test cases)
            # candidate = words[random.randint(0, len(words) - 1)]

            # Approach 2: histogram-based min-max heuristic
            hist = {}
            for w1 in words:
                hist_w = [0] * 7  # -1, 0, 1, ..., 6
                for w2 in words:
                    hist_w[self.get_matches(w1, w2)] += 1
                hist[w1] = max(hist_w)
            candidate = min(words, key=lambda w: hist[w])

            matches = master.guess(candidate)
            if matches == L:
                return
            candidates = []
            for w in words:
                if matches == self.get_matches(candidate, w):
                    candidates.append(w)
            words = candidates

    @staticmethod
    def get_matches(w1, w2):
        return sum(c1 == c2 for c1, c2 in zip(w1, w2))

# @lc code=end

