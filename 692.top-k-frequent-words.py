#
# @lc app=leetcode id=692 lang=python3
#
# [692] Top K Frequent Words
#
import heapq
from collections import defaultdict
from typing import *

# @lc code=start
class Node:
    def __init__(self, word, freq):
        self.word = word
        self.freq = freq

    def __lt__(self, other):
        if self.freq == other.freq:
            return self.word > other.word
        return self.freq < other.freq


class Solution:
    # T: O(n * log(k))
    # S: O(n)
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        cnt = defaultdict(int)
        for w in words:
            cnt[w] += 1
        
        heap: List[Node] = []

        # To keep the space usage k, instead of simulating a max heap with 
        # elements (-c, w), define a node type with customized comparator,
        # such that heap top is the least element with the largest lexicographical
        # rank. Lastly, results are written to the container reversely. 
        for w, c in cnt.items():
            node = Node(w, c)
            if len(heap) == k:
                heapq.heappushpop(heap, node)
            else:
                heapq.heappush(heap, node)

        res = [""] * len(heap)
        for i in range(k - 1, -1, -1):
            res[i] = heapq.heappop(heap).word
        return res

# @lc code=end

