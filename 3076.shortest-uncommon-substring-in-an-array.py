from typing import List, Optional


class TrieNode:
    def __init__(self):
        self.children: List[Optional[TrieNode]] = [None] * 26
        self.original_string_idxs = set()


class Solution:
    # T: O(n * l ^ 3), n := len(arr), l := string length
    # S: O(n * l)
    def shortestSubstrings(self, arr: List[str]) -> List[str]:
        OFFSET = ord('a')
        root = TrieNode()
        for i, s in enumerate(arr):
            n = len(s)

            # Generate all substrings and add to trie
            for j in range(n):
                tmp = []
                for k in range(j, n):
                    tmp.append(s[k])

                    cur = root
                    for l in range(len(tmp)):
                        cidx = ord(tmp[l]) - OFFSET
                        if cur.children[cidx] is None:
                            cur.children[cidx] = TrieNode()
                        cur = cur.children[cidx]
                        cur.original_string_idxs.add(i)

        res = [""] * len(arr)
        for i, s in enumerate(arr):
            ret = []
            n = len(s)

            # Generate all substrings and check trie
            for j in range(n):
                tmp = []
                for k in range(j, n):
                    tmp.append(s[k])

                    cur = root
                    cnt = -1
                    for l in range(len(tmp)):
                        cidx = ord(tmp[l]) - OFFSET
                        if cur.children[cidx] is None:
                            break
                        cur = cur.children[cidx]
                        cnt = len(cur.original_string_idxs)
                    
                    if cnt != 1:
                        # substring appears in other strings
                        continue
                    
                    # Get the lexicographically smallest substring
                    if len(ret) == 0 or len(ret) > len(tmp):
                        ret = tmp[:]
                    elif len(ret) == len(tmp):
                        for l in range(len(ret)):
                            a = tmp[l]
                            b = ret[l]
                            if a > b:
                                break
                            if a < b:
                                ret = tmp[:]
                                break
            res[i] = ''.join(ret)

        return res
