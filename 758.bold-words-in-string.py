#
# @lc app=leetcode id=758 lang=python3
#
# [758] Bold Words in String
#
from typing import List

# @lc code=start
class Solution:
    # KMP + string + boolean array
    # T: O(len(words) * (m + n))
    # S: O(len(words) * m + n), or O(m + n) if input words are unique
    def boldWords(self, words: List[str], s: str) -> str:
        n = len(s)
        words = set(words)

        if n == 0 or len(words) == 0:
            return s

        is_bold = [False] * n
        
        for w in words:
            m = len(w)
            lps = [0] * m
            i = 1 
            j = 0
            while i < m:
                # compute for w[i:j+1]
                if w[i] == w[j]:
                    lps[i] = j + 1 
                    i += 1 
                    j += 1
                elif j > 0:
                    j = lps[j - 1]
                else:
                    # lps[i] = 0
                    i += 1
            
            i = j = 0
            last = -1
            while i < n:
                if s[i] == w[j]:
                    if j == m - 1:
                        # Avoid marking true repetitively
                        start = max(last + 1, i - m + 1)
                        for k in range(start, i + 1):
                            is_bold[k] = True
                        last = i

                        # Generalized: get all matches
                        j = lps[j]
                        i += 1
                    else:
                        i += 1
                        j += 1
                else:
                    if j > 0: 
                        j = lps[j - 1]
                    else:
                        i += 1

        # Construct result string based on boolean
        res = []
        open_flag = True
        for i in range(n):
            if open_flag and is_bold[i]:
                res.append('<b>')
                open_flag = False
            elif not open_flag and not is_bold[i]:
                res.append('</b>')
                open_flag = True
            res.append(s[i])
        
        # don't forget the last closing tag
        if not open_flag:
            res.append('</b>')

        return ''.join(res)

# @lc code=end

