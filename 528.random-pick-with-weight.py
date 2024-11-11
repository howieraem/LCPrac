#
# @lc app=leetcode id=528 lang=python3
#
# [528] Random Pick with Weight
#
from random import randint
from typing import *

# @lc code=start
class Solution:

    def __init__(self, w: List[int]):
        self.n = len(w)
        self.psum = [0] * self.n
        self.psum[0] = w[0]
        for i in range(1, self.n):
            self.psum[i] = self.psum[i - 1] + w[i]

    def pickIndex(self) -> int:
        # Generates a random int in [0, self.psum[-1] - 1],
        # and returns the index of the interval between 
        # two prefix sums the random number falls into.
        # The interval lengths relative to [0, self.psum[-1] - 1]
        # reflect the weights.
        target = randint(0, self.psum[-1] - 1)
        l = 0
        r = self.n - 1
        while l <= r:
            m = l + ((r - l) >> 1)
            if self.psum[m] > target:
                r = m - 1
            else:   # NOTE: When self.psum[m] == target, need to pick the next index
                l = m + 1
        return l


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
# @lc code=end

