from typing import List

class TrieNode:
    def __init__(self):
        self.children = [None] * 10

class Solution:
    # T: O(len(arr1) + len(arr2))
    # S: O(alpha_size * max(len(str(x)) for x in arr1 + arr2))
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        root = TrieNode()
        
        # Build a trie with numbers in arr1
        for x in arr1:
            s = str(x)
            cur = root
            for c in s:
                ci = int(c)
                if cur.children[ci] is None:
                    cur.children[ci] = TrieNode()
                cur = cur.children[ci]

        # Check prefix existence of every number in arr2
        ans = 0
        for x in arr2:
            s = str(x)
            length = 0
            cur = root
            for c in s:
                ci = int(c)
                if cur.children[ci] is None:
                    break
                length += 1
                cur = cur.children[ci]

            ans = max(ans, length)

        return ans
