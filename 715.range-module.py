#
# @lc app=leetcode id=715 lang=python3
#
# [715] Range Module
#
from bisect import bisect_left, bisect_right

# @lc code=start
class RangeModule:
    def __init__(self):
        self.track = []  # length is always even

    # T: O(n)
    def addRange(self, left: int, right: int) -> None:
        start = bisect_left(self.track, left)
        end = bisect_right(self.track, right)
        subtrack = []
        # If the index is even, it means that it is currently outside the range of 
        # start and end indexes being tracked. In this case, update the track array.
        if (start & 1) == 0:
            subtrack.append(left)
        if (end & 1) == 0:
            subtrack.append(right)

        # Behavior of Python slicing below: if start == end, then `subtrack` is inserted to `track` 
        # at index start, without overwriting elements after index start; if start != end, then after 
        # insertion subtrack[0] will be at index start, and track[start + 1:] will be overwritten
        # by subtrack[1:].
        self.track[start:end] = subtrack

    # T: O(log(n))
    def queryRange(self, left: int, right: int) -> bool:
        start = bisect_right(self.track, left)
        end = bisect_left(self.track, right)
        # Rules in `track`: odd indices are the end points of ranges being tracked,
        # while even indices are the start points of ranges being tracked.
        # Example of self.track [10, 14, 16, 20]:
        #   ranges being tracked: [10, 14), [16, 20)
        #   ranges not being tracked: [14. 16)
        # If start == end, then left and right lie in the same range.
        # If start is odd, then the interval is tracked.
        return start == end and (start & 1)

    # T: O(n)
    def removeRange(self, left: int, right: int) -> None:
        start = bisect_left(self.track, left)
        end = bisect_right(self.track, right)
        subtrack = []
        # If the index is odd, it means that it is currently inside the range of 
        # start and end indexes being tracked. In this case, update the track array.
        if start & 1:
            subtrack.append(left)
        if end & 1:
            subtrack.append(right)

        # Behavior of Python slicing below: if start == end, then `subtrack` is inserted to `track` 
        # at index start, without overwriting elements after index start; if start != end, then after 
        # insertion subtrack[0] will be at index start, and track[start + 1:] will be overwritten
        # by subtrack[1:].
        self.track[start:end] = subtrack


# Your RangeModule object will be instantiated and called as such:
# obj = RangeModule()
# obj.addRange(left,right)
# param_2 = obj.queryRange(left,right)
# obj.removeRange(left,right)
# @lc code=end

