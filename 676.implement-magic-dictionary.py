#
# @lc app=leetcode id=676 lang=python3
#
# [676] Implement Magic Dictionary
#
from typing import *


# @lc code=start
OFFSET = ord('a')


# S: O(alpha_size * n)
class MagicDictionary:
    class TrieNode:
        def __init__(self):
            self.children: List[Optional[MagicDictionary.TrieNode]] = [None] * 26
            self.is_word = False

    # T: O(alpha_size)
    def __init__(self):
        self.root = self.TrieNode()        

    # T: O(sum(len(w) for w in dictionary) * alpha_size)
    def buildDict(self, dictionary: List[str]) -> None:
        for w in dictionary:
            cur = self.root
            for c in w:
                ci = ord(c) - OFFSET
                if cur.children[ci] is None:
                    cur.children[ci] = self.TrieNode()
                cur = cur.children[ci]
            cur.is_word = True

    # replace each char in searchWord and search in trie (with pruning)
    # T: O(n * alpha_size)
    def search(self, searchWord: str) -> bool:
        def search_helper(
                    s: List[str], 
                    start_node: MagicDictionary.TrieNode, 
                    start_idx: int) -> bool:
            if start_node is None:
                return False
            cur = start_node
            for i in range(start_idx, len(s)):
                ci = ord(s[i]) - OFFSET
                if cur.children[ci] is None:
                    return False
                cur = cur.children[ci]
            return cur.is_word
        
        searchWord = list(searchWord)  # for inplace modification
        cur = self.root
        
        for i in range(len(searchWord)):
            ci = ord(searchWord[i]) - OFFSET

            # try replacing every char, and search from cur node and idx
            for j in range(26):
                if j == ci or cur.children[j] is None:
                    # skip same char, or a leading char without available suffixes
                    continue
                if search_helper(searchWord, cur.children[j], i + 1):
                    return True

            if cur.children[ci] is None:
                return False
            cur = cur.children[ci]

        return False
        

# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dictionary)
# param_2 = obj.search(searchWord)
# @lc code=end

