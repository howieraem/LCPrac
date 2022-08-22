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
    # candidates after each time we call guess(w). However, calling 
    # guess(w) less than 10 times is not strictly guaranteed.
    # T: O(n^2 * l), n := initial len(wordlist), l := word length
    # S: O(n)
    def findSecretWord(self, words: List[str], master: 'Master') -> None:
        MAX_GUESSES = 10
        L = len(words[0])  # 6
        matches = 0
        for _ in range(MAX_GUESSES):
            # Approach 1: random guess (more likely to fail some test cases)
            # https://leetcode.com/problems/guess-the-word/discuss/556075
            # candidate = words[random.randint(0, len(words) - 1)]

            # Approach 2: histogram-based min-max heuristic
            """
            https://leetcode.com/problems/guess-the-word/discuss/134251
            In order to maximize the number of words we eliminate at each guess, 
            we choose a guess that partitions the potential candidate set roughly 
            equally by all possible distances. That is, if we choose a guess that 
            is roughly equally at distance 0 from 1/6 of all words, distance 1 
            from 1/6 of all words, etc., we know that whatever distance the secret 
            happens to be from the guess, we can eliminate a substantial number of 
            words. This is where we use a min-max heuristic. For each word, we 
            compute a histogram of its distance from every word in the candidate 
            set, and then select the word whose histogram peak is the smallest.
            """
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
            words = list(filter(lambda w: self.get_matches(w, candidate) == matches, words))

    @staticmethod
    def get_matches(w1, w2):
        return sum(c1 == c2 for c1, c2 in zip(w1, w2))

# @lc code=end

