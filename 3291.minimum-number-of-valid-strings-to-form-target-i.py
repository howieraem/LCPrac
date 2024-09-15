from typing import *


class TrieNode:
    def __init__(self):
        self.children: List[Optional[TrieNode]] = [None] * 26


class Solution:
    # T: O(len(target) ^ 2 * max(len(w) for w in words))
    # S: O(len(words) + len(target))
    def minValidStrings(self, words: List[str], target: str) -> int:
        seen = set()
        OFFSET = ord('a')
        root = TrieNode()
        for w in words:
            if w in seen:
                continue
            cur = root
            for c in w:
                cidx = ord(c) - OFFSET
                if not cur.children[cidx]:
                    cur.children[cidx] = TrieNode()
                cur = cur.children[cidx]
            seen.add(w)

        def is_prefix(s, l, r):
            cur = root
            for i in range(l, r):
                cidx = ord(s[i]) - OFFSET
                if not cur.children[cidx]:
                    return False
                cur = cur.children[cidx]
            return True

        n = len(target)
        dp = [0] * (n + 1)
        not_feasible = [False] * n
        for i in range(1, n + 1):
            if i > 1 and dp[i - 1] == 0:
                return -1
            for j in range(i):
                if not_feasible[j]:
                    continue
                if not is_prefix(target, j, i):
                    not_feasible[j] = True
                    continue
                if (j == 0 or dp[j] > 0):
                    dp[i] = dp[j] + 1
                    break
        return dp[n] if dp[n] > 0 else -1
