#
# @lc app=leetcode id=418 lang=python3
#
# [418] Sentence Screen Fitting
#
from typing import List

# @lc code=start
class Solution:
    # Intuitive solution
    # T: O(n + rows * l), n := len(sentence), l := sentence word length
    # S: O(n)
    def wordsTyping(self, sentence: List[str], rows: int, cols: int) -> int:
        s = " ".join(sentence) + ' '
        N = len(s)
        char_cnt = 0
        for _ in range(rows):
            char_cnt += cols
            if s[char_cnt % N] == ' ':
                # The word in front of a space occupies up to 
                # the end of the current row, so this space 
                # char can be omitted.
                char_cnt += 1
            else:
                # Current word cannot fit into the current row.
                while char_cnt > 0 and s[(char_cnt - 1) % N] != ' ':
                    char_cnt -= 1
        return char_cnt // N
    
    '''
    # DP-based solution
    # T: O(n + rows), n := len(sentence)
    # S: O(n)
    def wordsTyping(self, sentence: List[str], rows: int, cols: int) -> int:
        s = " ".join(sentence) + ' '
        N = len(s)

        # `offset` is the distance from char s[i] to the initial position of the current word.
        # Example: 
        #   If s = "hello world ", then `offset` will be
        #   [0, -1, -2, -3, -4, 1, 0, -1, -2, -3, -4, 1]
        offset = [0] * N
        for i in range(1, N):
            if s[i] == ' ':
                offset[i] = 1
            else:
                offset[i] = offset[i - 1] - 1

        char_cnt = 0
        for _ in range(rows):
            char_cnt += cols
            # If offset[char_cnt % N] < 0: 
            #   Current word cannot fit into the current row.
            # If offset[char_cnt % N] == 1: 
            #   The word in front of a space occupies up to 
            #   the end of the current row, so this space 
            #   char can be omitted.
            char_cnt += offset[char_cnt % N]
        return char_cnt // N
    '''

# @lc code=end

