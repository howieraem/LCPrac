#
# @lc app=leetcode id=1233 lang=python3
#
# [1233] Remove Sub-Folders from the Filesystem
#
from collections import deque
from typing import *

# @lc code=start
OFFSET = ord('a')

class Solution:
    class TrieNode:
        def __init__(self):
            self.children: List[Optional[Solution.TrieNode]] = [None] * 27  # add 1 for '/'
            self.folder_idx = -1

    @staticmethod
    def cidx(c: str) -> int:
        return 26 if c == '/' else ord(c) - OFFSET

    # T: O(n * (w + alpha_size)), w := max folder path length
    # S: O(alpha_size * w)
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        root = self.TrieNode()

        # Build Trie
        for i, w in enumerate(folder):
            cur = root
            for c in w:
                ci = self.cidx(c)
                if cur.children[ci] is None:
                    cur.children[ci] = self.TrieNode()
                cur = cur.children[ci]
            cur.folder_idx = i

        # BFS
        res = []
        q: Deque[Solution.TrieNode] = deque()
        q.append(root)
        while len(q) > 0:
            node = q.popleft()
            if node.folder_idx != -1:
                res.append(folder[node.folder_idx])
            
            for i in range(27):
                # IMPORTANT: assume parent folder will not end with '/'
                if node.children[i] is not None and not (i == 26 and node.folder_idx != -1):
                    q.append(node.children[i])
        
        return res


# @lc code=end

