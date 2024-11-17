#
# @lc app=leetcode id=1032 lang=python3
#
# [1032] Stream of Characters
#
from typing import *

# @lc code=start
OFFSET = ord('a')

def cid(c):
    return ord(c) - OFFSET

class TrieNode:
    def __init__(self):
        self.children: List[Optional[TrieNode]] = [None] * 26
        self.is_word: bool = False

# Trie + suffix
# S: O(n * l)
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

    # trick: search backwards, check if the reversed word(s) is in the trie
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
    
    # follow-up: words can be added dynamically; return all words matching sequence
    # maintain the max length of words added; suffix search window should be no longer 
    # than this max length (use a queue to pop the earlier chars).

# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)
# @lc code=end

