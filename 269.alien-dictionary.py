#
# @lc app=leetcode id=269 lang=python3
#
# [269] Alien Dictionary
#
from collections import deque
from typing import *

# @lc code=start
A = ord('a')

def cid(c):
    return ord(c) - A

class Solution:
    # Graph BFS + topological sort
    # Build a DAG graph so that we can get a possible order without invalid dependencies.
    # T: O(n * l + s ^ 2), n := len(words), l := max word length, s := 26
    # S: O(s ^ 2)
    def alienOrder(self, words: List[str]) -> str:
        graph = [[False] * 26 for _ in range(26)]
        in_deg = [-1 for _ in range(26)]  # default to -1 for non-existent chars
        n_uniq_chars = 0

        for w in words:
            for c in w:
                c = cid(c)
                if in_deg[c] == -1:
                    in_deg[c] = 0
                    n_uniq_chars += 1

        # Build a graph by checking each adjacent pairs of words 
        # (should be sorted lexicographically in the Alien language) 
        for i in range(1, len(words)):
            w1 = words[i - 1]
            w2 = words[i]
            n1 = len(w1)
            n2 = len(w2)
            n = min(n1, n2)
            for j in range(n):
                # compare chars at same index
                if w1[j] != w2[j]:
                    c1 = cid(w1[j])
                    c2 = cid(w2[j])
                    
                    # Form an edge from c1 to c2
                    if not graph[c1][c2]:
                        graph[c1][c2] = True
                        in_deg[c2] += 1
                    
                    break
                
                if j == n - 1 and n1 > n2:
                    # Invalid order
                    return ""
        
        # Topological sort to detect cycle
        res = []
        q = deque()
        for i in range(len(in_deg)):
            if in_deg[i] == 0:
                q.append(i)

        while len(q) > 0:
            i = q.popleft()
            res.append(chr(i + A))
            for j in range(len(graph[i])):
                if graph[i][j]:
                    in_deg[j] -= 1
                    if in_deg[j] == 0:
                        q.append(j)

        # Cycle exists if len(res) != n_uniq_chars
        # The result is the lexicographically increasing order of the chars in this language.
        return "".join(res) if len(res) == n_uniq_chars else ""
    
    # Similar problems: given some candidate subsequences, check if they are drawn 
    # from the same sequence with unique numbers

# @lc code=end

