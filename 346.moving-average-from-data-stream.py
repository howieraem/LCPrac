#
# @lc app=leetcode id=346 lang=python3
#
# [346] Moving Average from Data Stream
#
from collections import deque

# @lc code=start
class MovingAverage:

    def __init__(self, size: int):
        self.q = deque()
        self.cap = size       
        self.sum = 0.

    def next(self, val: int) -> float:
        if len(self.q) == self.cap:
            self.sum -= self.q.popleft()
        self.q.append(val)
        self.sum += val
        return self.sum / len(self.q)

# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
# @lc code=end

