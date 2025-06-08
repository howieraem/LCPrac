#
# @lc app=leetcode id=1408 lang=python3
#
# [1408] String Matching in an Array
#
from typing import *

# @lc code=start
OFFSET = ord('a')

class Solution:
    class TrieNode:
        def __init__(self):
            self.freq: int = 0
            self.children: List[Optional[Solution.TrieNode]] = [None] * 26

    # Trie
    # T: O(len(words) * max(len(w) for w in words) ^ 2)
    # S: O(len(words) * max(len(w) for w in words) ^ 2)
    def stringMatching(self, words: List[str]) -> List[str]:
        root = self.TrieNode()
        for w in words:
            for start in range(len(w)):
                self.__insert_word(root, w[start:])
        
        res = []
        for w in words:
            if self.__is_substr(root, w):
                res.append(w)
        return res

    @staticmethod
    def __insert_word(root: TrieNode, s: str) -> None:
        cur = root
        for c in s:
            ci = ord(c) - OFFSET
            if cur.children[ci] is None:
                cur.children[ci] = Solution.TrieNode()
            cur = cur.children[ci]
            cur.freq += 1

    @staticmethod
    def __is_substr(root: TrieNode, s: str) -> bool:
        cur = root
        for c in s:
            ci = ord(c) - OFFSET
            if cur.children[ci] is None:
                return False
            cur = cur.children[ci]
        return cur.freq > 1

# @lc code=end

