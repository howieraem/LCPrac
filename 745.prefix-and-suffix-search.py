#
# @lc app=leetcode id=745 lang=python3
#
# [745] Prefix and Suffix Search
#
from typing import *

# @lc code=start
"""Solution with 1 trie and string augmentations"""
SEPARATOR = '{'  # this char is next to 'z' in ASCII, for easier index computation

def cidx(c):
    return ord(c) - ord('a')

class TrieNode:
    def __init__(self):
        self.children: List[Optional[TrieNode]] = [None] * 27  # lowercase letters and a special separator char
        self.last_seen_idx: int = 0  # need to return the largest valid index

class WordFilter:
    # T: O(n * l ^ 2), n := len(words), l := avg word length
    def __init__(self, words: List[str]):
        self.root = TrieNode()
        for i in range(len(words)):
            for sep_i in range(len(words[i])):
                # Augment the original word to have a variety of suffixes in front. For example, 
                # "apple" will produce: 
                # "apple{apple", "pple{apple", "ple{apple", "le{apple", "e{apple", "{apple"
                w = words[i][sep_i:] + SEPARATOR + words[i]
                self._insert(w, i)

    # T: O(len(pref) + len(suff))
    def f(self, pref: str, suff: str) -> int:
        node = self.root
        for c in (suff + SEPARATOR + pref):  # IMPORTANT
            ci = cidx(c)
            if node.children[ci] is None:
                return -1
            node = node.children[ci]
        return node.last_seen_idx

    def _insert(self, w: str, last_seen_idx: int):
        node = self.root
        for c in w:
            ci = cidx(c)
            if node.children[ci] is None:
                node.children[ci] = TrieNode()
            node = node.children[ci]
            node.last_seen_idx = last_seen_idx

# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(pref,suff)
# @lc code=end

