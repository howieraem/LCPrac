#
# @lc app=leetcode id=855 lang=python3
#
# [855] Exam Room
#
from heapq import *

# @lc code=start
# Heap + Hash maps + Greedy?
# Rules: When a student enters the room, they must sit in the seat that 
# maximizes the distance to the closest person. If there are multiple 
# such seats, they sit in the seat with the lowest number. If no one is 
# in the room, then the student sits at seat number 0.
# S: O(n)
class ExamRoom:
    # T: O(1)
    def __init__(self, n: int):
        self.n = n
        self.max_heap = []  # max heap of (dist_to_closest_allocated_seat, segment_start, segment_end, is_valid)
        self.avail_first = dict()  # k: segment_start, v: segment
        self.avail_last = dict()   # k: segment_end, v: segment
        self._put_segment(0, n - 1)
    
    # Add a segment [first, last], any seats in between are available
    # T: O(log(n))
    def _put_segment(self, first, last):
        if first == 0 or last == self.n - 1:
            # edge cases: first and second ever seats
            dist = last - first
        else:
            dist = (last - first) >> 1

        seg = [-dist, first, last, True]
        self.avail_first[first] = seg
        self.avail_last[last] = seg
        heappush(self.max_heap, seg)

    # T: O(n * log(n)) worst if only leave() have been invoked many times just before; O(log(n)) amortised?
    def seat(self) -> int:
        if len(self.max_heap) == 0:
            # this shouldn't happen
            self._put_segment(0, self.n - 1)
        
        _, first, last, valid = heappop(self.max_heap)
        while not valid:
            _, first, last, valid = heappop(self.max_heap)
        del self.avail_first[first]
        del self.avail_last[last]

        # Edge cases: first avail seat should be 0, second avail seat should be n - 1
        if first == 0:
            ans = 0
            if first != last:
                self._put_segment(first + 1, last)
        elif last == self.n - 1:
            ans = last
            if first != last:
                self._put_segment(first, last - 1)
        else:
        # Other cases: seats between 0 and n - 1, just assign the midpoint of the widest segment
            ans = (first + last) >> 1
            if ans > first:
                self._put_segment(first, ans - 1)
            if ans < last:
                self._put_segment(ans + 1, last)
        return ans

    # T: O(log(n))
    def leave(self, p: int) -> None:
        first = last = p
        left, right = p - 1, p + 1

        # Also need to "merge" left and right segments; 
        # Delete from heap and maps unless edge cases 0 and n - 1
        if left >= 0 and left in self.avail_last:
            seg_left = self.avail_last.pop(left)
            seg_left[3] = False   # will be deleted in next seat() call
            first = seg_left[1]
        
        if right < self.n and right in self.avail_first:
            seg_right = self.avail_first.pop(right)
            seg_right[3] = False  # will be deleted in next seat() call
            last = seg_right[2]
        
        self._put_segment(first, last)


# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(n)
# param_1 = obj.seat()
# obj.leave(p)
# @lc code=end

