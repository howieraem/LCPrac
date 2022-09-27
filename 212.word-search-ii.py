#
# @lc app=leetcode id=212 lang=python3
#
# [212] Word Search II
#
from typing import *

# @lc code=start
class TrieNode:
    def __init__(self):
        self.children: List[Optional[TrieNode]] = [None] * 26
        self.word: str = ""

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        D = (0, 1, 0, -1, 0)
        m, n = len(board), len(board[0])
        
        n_words = len(words)  # words are unique
        root = TrieNode()
        for w in words:
            node = root
            for c in w:
                ci = ord(c) - ord('a')
                if node.children[ci] is None:
                    node.children[ci] = TrieNode()
                node = node.children[ci]
            node.word = w

        res = []

        def backtrack(r: int, c: int, cur_node: TrieNode):
            nonlocal n_words
            if n_words == 0:
                return
            ch = board[r][c]
            if ch == '#':
                return
            ci = ord(ch) - ord('a')
            if cur_node.children[ci] is None:
                return 
            cur_node = cur_node.children[ci]

            if len(cur_node.word):
                res.append(cur_node.word)
                cur_node.word = ""  # IMPORTANT: do this to avoid duplicates in res

                # IMPORTANT: prevent further recursions after all words found, otherwise TLE
                n_words -= 1
            
            board[r][c] = '#'
            for d in range(4):
                nr, nc = r + D[d], c + D[d + 1]
                if 0 <= nr < m and 0 <= nc < n:
                    backtrack(nr, nc, cur_node)
            board[r][c] = ch

        # Do backtracking on every cell
        for i in range(m):
            for j in range(n):
                backtrack(i, j, root)
                if n_words == 0:
                    # IMPORTANT: prevent further recursions after all words found, otherwise TLE
                    return res
        
        return res


# @lc code=end

