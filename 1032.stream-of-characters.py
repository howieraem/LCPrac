#
# @lc app=leetcode id=1032 lang=python3
#
# [1032] Stream of Characters
#
from typing import *

# @lc code=start
def cid(c):
    return ord(c) - ord('a')

class TrieNode:
    def __init__(self):
        self.children: List[Optional[TrieNode]] = [None] * 26
        self.is_word: bool = False

class StreamChecker:
    # T: O(n * l)
    def __init__(self, words: List[str]):
        self.chars = []
        self.root = TrieNode()
        for w in words:
            node = self.root
            for c in reversed(w):  # suffix trie
                i = cid(c)
                if node.children[i] is None:
                    node.children[i] = TrieNode()
                node = node.children[i]
            node.is_word = True

    # T: O(l)
    def query(self, letter: str) -> bool:
        self.chars.append(letter)
        node = self.root
        for c in reversed(self.chars):  # check backwards
            i = cid(c)
            if node.children[i] is None:
                return False
            node = node.children[i]
            if node.is_word:
                return True
        return False

# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)
# @lc code=end

