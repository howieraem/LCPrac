#
# @lc app=leetcode id=792 lang=python3
#
# [792] Number of Matching Subsequences
#
from collections import defaultdict, Counter
from typing import List

# @lc code=start
class Solution:
    '''
    # Solution 1: Brute-force
    # T: O(m * n * l), m := len(s), n := len(words), l := max. word length of words
    # S: O(n)
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        cnts = Counter(words)
        ans = 0
        for w in cnts:
            i = 0
            j = 0
            while i < len(s) and j < len(w):
                j += s[i] == w[j]
                i += 1
            
            if j == len(w):
                ans += cnts[w]
        return ans
    '''

    '''
    # Solution 2: construct buckets with each char in words
    # T: O(m * n * l), m := len(s), n := len(words), l := max. word length of words
    # S: O(n * l)
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        words_start_with_char = defaultdict(list)
        for w in words:
            words_start_with_char[w[0]].append(w)

        ans = 0
        for c in s:
            w_candidates = words_start_with_char[c]
            if not len(w_candidates):
                continue
            words_start_with_char[c] = []
            for w in w_candidates:
                if len(w) == 1:
                    # Candidate word reduced to a single char,
                    # a subseq is found
                    ans += 1
                else:
                    words_start_with_char[w[1]].append(w[1:])
        return ans
    '''

    # Solution 3: similar to solution 2, but avoids copying characters and is thus optimized
    # T: O(len(s) + sum(len(w) for w in words))
    # S: O(sum(len(w) for w in words))
    class Node:
        def __init__(self, word: str):
            self.word = word
            self.idx = 0
    
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        words_start_with_char = defaultdict(list)
        for w in words:
            words_start_with_char[w[0]].append(self.Node(w))
        
        ans = 0
        for c in s:
            w_candidates = words_start_with_char[c]
            if not len(w_candidates):
                continue
            words_start_with_char[c] = []
            for node in w_candidates:
                node.idx += 1
                if node.idx == len(node.word):
                    ans += 1
                else:
                    words_start_with_char[node.word[node.idx]].append(node)
        return ans


# @lc code=end

