#
# @lc app=leetcode id=158 lang=python3
#
# [158] Read N Characters Given read4 II - Call Multiple Times
#
from typing import List

def read4(buf4: List[str]) -> int:
    raise NotImplementedError

# @lc code=start
# The read4 API is already defined for you.
# def read4(buf4: List[str]) -> int:

class Solution:
    def __init__(self):
        self.buf4 = [''] * 4
        self.buf4_idx = 0
        self.n_unread_chars_in_buf4 = 0

    # T: O(n // k), k := 4
    # S: O(k)
    def read(self, buf: List[str], n: int) -> int:
        if self.n_unread_chars_in_buf4 == 0:
            self.n_unread_chars_in_buf4 = read4(self.buf4)
            self.buf4_idx = 0
        
        p = 0
        while p < n and self.n_unread_chars_in_buf4 != 0:
            buf[p] = self.buf4[self.buf4_idx]
            p += 1
            self.buf4_idx += 1
            self.n_unread_chars_in_buf4 -= 1

            if self.n_unread_chars_in_buf4 == 0:
                self.n_unread_chars_in_buf4 = read4(self.buf4)
                self.buf4_idx = 0
            
        return p

# @lc code=end

