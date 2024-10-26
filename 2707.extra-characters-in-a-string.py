from typing import *


class TrieNode:
    def __init__(self):
        self.children: List[Optional[TrieNode]] = [None] * 26
        self.is_word: bool = False


class Solution:
    # Trie + DP
    # T: O(n ^ 2 + sum(len(w) for w in dictionary)), n := len(s)
    # S: O(n + sum(len(w) for w in dictionary))
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        OFFSET = ord('a')

        # Build trie
        root = TrieNode()
        for w in dictionary:
            cur = root
            for c in w:
                ci = ord(c) - OFFSET
                if cur.children[ci] is None:
                    cur.children[ci] = TrieNode()
                cur = cur.children[ci]
            cur.is_word = True

        n = len(s)

        # dp[i] means the min. no. of extra chars required for s[i:]
        # The reason for this suffix formulation is that we want better control 
        # over how to split and traverse the trie
        dp = [float('inf')] * (n + 1)
        dp[n] = 0  # base case: an empty string needs no extra char
        
        # Because of dp's definition, we update dp from the back of s
        for i in range(n - 1, -1, -1):
            # init worst case: assume we need s[i] as the extra char
            dp[i] = dp[i + 1] + 1

            cur = root
            for j in range(i, n):
                ci = ord(s[j]) - OFFSET
                # Use the trie to reduce search space
                if cur.children[ci] is None:
                    break
                cur = cur.children[ci]
                if cur.is_word:
                    # use a word from dictionary
                    dp[i] = min(dp[i], dp[j + 1])

        return dp[0]
