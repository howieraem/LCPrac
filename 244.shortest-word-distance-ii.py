#
# @lc app=leetcode id=244 lang=python3
#
# [244] Shortest Word Distance II
#
from collections import defaultdict
from typing import List

# @lc code=start
class WordDistance:
    # T: O(n)
    # S: O(n)
    def __init__(self, wordsDict: List[str]):
        self.word_idxs = defaultdict(list)
        for i, w in enumerate(wordsDict):
            self.word_idxs[w].append(i)
        
        # Assume no more words will be added, can cache the query results
        # k: (w1, w2), v: shortest dist 
        self.cache = dict()

    # T: O(n)
    # S: O(1)
    def shortest(self, word1: str, word2: str) -> int:
        cache_k = (word1, word2)
        cache_v = self.cache.get(cache_k, -1)
        if cache_v != -1:
            return cache_v

        idxs1 = self.word_idxs[word1]
        idxs2 = self.word_idxs[word2]
        if len(idxs1) == 0 or len(idxs2) == 0:
            return -1
        ans = float('inf')
        i = 0
        j = 0
        while i < len(idxs1) and j < len(idxs2):
            idx1 = idxs1[i]
            idx2 = idxs2[j]
            if idx1 > idx2:
                ans = min(ans, idx1 - idx2)
                j += 1
            else:
                ans = min(ans, idx2 - idx1)
                i += 1
            
            if ans == 1:
                # minimum valid distance, stop early
                break
        
        self.cache[cache_k] = ans
        return ans


# Your WordDistance object will be instantiated and called as such:
# obj = WordDistance(wordsDict)
# param_1 = obj.shortest(word1,word2)
# @lc code=end

