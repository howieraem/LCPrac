#
# @lc app=leetcode id=720 lang=python3
#
# [720] Longest Word in Dictionary
#
from collections import deque
from typing import *

# @lc code=start
def cid(c):
    return ord(c) - ord('a')

class TrieNode:
    def __init__(self):
        self.children: List[Optional[TrieNode]] = [None] * 26
        self.w = ""

class Solution:
    # T: O(n * l)
    # S: O(n * l)
    def longestWord(self, words: List[str]) -> str:
        self.root = TrieNode()
        
        # insert words into trie
        for w in words:
            node = self.root
            for c in w:
                i = cid(c)
                if node.children[i] is None:
                    node.children[i] = TrieNode()
                node = node.children[i]
            node.w = w
        
        # BFS: find the longest word in trie
        q: Deque[TrieNode] = deque()
        q.append(self.root)
        res = ""
        while len(q):
            node = q.popleft()
            for child in node.children:
                if child and len(child.w):
                    q.append(child)
                    # If there is more than one possible answer, return the longest word with 
                    # the smallest lexicographical order.
                    # As we are doing BFS, the longer words will appear later and the condition is
                    # len(child.w) > len(res) rather than len(child.w) >= len(res)
                    if len(child.w) > len(res) or child.w < res:
                        res = child.w
        return res
        
# @lc code=end

