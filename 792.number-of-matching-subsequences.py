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
            if len(w) > len(s):
                continue
            words_start_with_char[w[0]].append(w)

        ans = 0
        for c in s:
            w_candidates = words_start_with_char[c]
            if len(w_candidates) == 0:
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

    # Solution 3: Advanced two pointers, similar to solution 2, but avoids copying characters and is thus optimized
    # T: O(len(s) + sum(len(w) for w in words))
    # S: O(sum(len(w) for w in words))
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        words_start_with_char = defaultdict(list)
        for w in words:
            if len(w) > len(s):
                continue
            words_start_with_char[w[0]].append([w, 0])  # word, current_char_idx
        
        ans = 0
        for c in s:
            w_candidates = words_start_with_char[c]
            if len(w_candidates) == 0:
                continue
            words_start_with_char[c] = []  # IMPORTANT: reset for every char in pattern s
            for word_info in w_candidates:
                word_info[1] += 1   # incr the word's current char idx by 1
                if word_info[1] == len(word_info[0]):
                    # idx reaches end of the word
                    ans += 1
                else:
                    cur_start_char = word_info[0][word_info[1]]
                    words_start_with_char[cur_start_char].append(word_info)
        return ans


# @lc code=end

