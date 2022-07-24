#
# @lc app=leetcode id=716 lang=python3
#
# [716] Max Stack
#
import heapq
from collections import deque

# @lc code=start
class MaxStack:
    def __init__(self):
        self.soft_del = set()
        self.min_heap = []
        self.stack = deque()
        self.next_id = 0

    # T: O(log(n))
    def push(self, x: int) -> None:
        heapq.heappush(self.min_heap, (-x, self.next_id))
        self.stack.append((x, self.next_id))
        self.next_id -= 1

    # T: O(1)
    def pop(self) -> int:
        x, idx = self.stack.pop()
        self.soft_del.add(idx)
        self._clean()
        return x

    # T: O(1)
    def top(self) -> int:
        return self.stack[-1][0]

    # T: O(1)
    def peekMax(self) -> int:
        return -self.min_heap[0][0]

    # T: O(log(n))
    def popMax(self) -> int:
        x, idx = heapq.heappop(self.min_heap)
        self.soft_del.add(idx)
        self._clean()
        return -x

    # T: O(1) amortized, each element only gets cleaned once
    def _clean(self) -> None:
        while len(self.stack) and self.stack[-1][1] in self.soft_del:
            self.soft_del.remove(self.stack.pop()[1])
        while len(self.min_heap) and self.min_heap[0][1] in self.soft_del:
            self.soft_del.remove(heapq.heappop(self.min_heap)[1])

# Your MaxStack object will be instantiated and called as such:
# obj = MaxStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.peekMax()
# param_5 = obj.popMax()
# @lc code=end

