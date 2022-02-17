#
# @lc app=leetcode id=855 lang=python3
#
# [855] Exam Room
#
from heapq import *

# @lc code=start
class ExamRoom:

    def __init__(self, n: int):
        self.n = n
        self.heap = []
        self.avail_first = dict()
        self.avail_last = dict()
        self._put_seg(0, n - 1)
    
    def _put_seg(self, first, last):
        if first == 0 or last == self.n - 1:
            priority = last - first
        else:
            priority = (last - first) >> 1

        seg = [-priority, first, last, True]    # negate priority to simulate max heap
        self.avail_first[first] = seg
        self.avail_last[last] = seg
        heappush(self.heap, seg)

    def seat(self) -> int:
        while True:
            _, first, last, valid = heappop(self.heap)
            if valid:
                del self.avail_first[first]
                del self.avail_last[last]
                break

        if first == 0:
            ret = 0
            if first != last:
                self._put_seg(first + 1, last)
        elif last == self.n - 1:
            ret = last
            if first != last:
                self._put_seg(first, last - 1)
        else:
            ret = (first + last) >> 1
            if ret > first:
                self._put_seg(first, ret - 1)
            if ret < last:
                self._put_seg(ret + 1, last)
        return ret

    def leave(self, p: int) -> None:
        first = last = p
        left, right = p - 1, p + 1
        if left >= 0 and left in self.avail_last:
            seg_left = self.avail_last.pop(left)
            seg_left[3] = False
            first = seg_left[1]
        
        if right < self.n and right in self.avail_first:
            seg_right = self.avail_first.pop(right)
            seg_right[3] = False
            last = seg_right[2]
        self._put_seg(first, last)


# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(n)
# param_1 = obj.seat()
# obj.leave(p)
# @lc code=end

