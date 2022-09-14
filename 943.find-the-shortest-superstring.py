#
# @lc app=leetcode id=943 lang=python3
#
# [943] Find the Shortest Superstring
#
from functools import lru_cache
from typing import *

# @lc code=start
class Solution:
    def shortestSuperstring(self, words: List[str]) -> str:
        """
        Traveling salesman problem. Model each word as a graph node,
        then find the path visiting all nodes with smallest cost.
        """
        @lru_cache(None)
        def get_min_cost_substr(pre_word: str, cur_word: str) -> str:
            """
            For the 2 given words, returns the substring with minimum cost 
            to build the superstring
            """
            for i in range(len(pre_word) + 1, 0, -1):
                if pre_word[-i:] == cur_word[:i]:
                    # Find the longest suffix (char order not reversed) of prev visited word 
                    # that equals the prefix the cur word, then discard the prefix of the 
                    # cur word.
                    return cur_word[i:]
            return cur_word
        
        n = len(words)

        @lru_cache(None)
        def dfs(pre: int, mask: int) -> str:
            res = ""
            if mask + 1 == (1 << n):
                # all words visited
                return res
            for i in range(n):
                if not mask & (1 << i):  # words[i] has not been visited
                    candidate = get_min_cost_substr(words[pre], words[i]) + dfs(i, mask | (1 << i))
                    if res == "" or len(res) > len(candidate):
                        res = candidate
            return res

        res = ""
        for i in range(n):
            candidate = words[i] + dfs(i, 1 << i)
            if res == "" or len(res) > len(candidate):
                res = candidate
        return res

# @lc code=end

