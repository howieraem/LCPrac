#
# @lc app=leetcode.cn id=284 lang=python3
#
# [284] 顶端迭代器
#

# @lc code=start
# Below is the interface for Iterator, which is already defined for you.
#
# class Iterator:
#     def __init__(self, nums):
#         """
#         Initializes an iterator object to the beginning of a list.
#         :type nums: List[int]
#         """
#
#     def hasNext(self):
#         """
#         Returns true if the iteration has more elements.
#         :rtype: bool
#         """
#
#     def next(self):
#         """
#         Returns the next element in the iteration.
#         :rtype: int
#         """

# class PeekingIterator:
#     """Assuming the base iterator will not iterate through null,
#     otherwise an auxiliary queue is needed to copy all elements 
#     from the base iterator."""

#     def __init__(self, iterator):
#         """
#         Initialize your data structure here.
#         :type iterator: Iterator
#         """
#         self.iter = iterator
#         self.cur = None
        

#     def peek(self):
#         """
#         Returns the next element in the iteration without advancing the iterator.
#         :rtype: int
#         """
#         if self.cur is None:
#             self.cur = self.iter.next()
#         return self.cur


#     def next(self):
#         """
#         :rtype: int
#         """
#         if self.cur is not None:
#             res = self.cur
#             self.cur = None
#             return res
#         return self.iter.next()
        

#     def hasNext(self):
#         """
#         :rtype: bool
#         """
#         return self.cur is not None or self.iter.hasNext()
from collections import deque


class PeekingIterator:
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """
        self.q = deque()
        while iterator.hasNext():
            self.q.append(iterator.next())


    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        return self.q[0]


    def next(self):
        """
        :rtype: int
        """
        return self.q.popleft()


    def hasNext(self):
        """
        :rtype: bool
        """
        return len(self.q) > 0
        

# Your PeekingIterator object will be instantiated and called as such:
# iter = PeekingIterator(Iterator(nums))
# while iter.hasNext():
#     val = iter.peek()   # Get the next element but not advance the iterator.
#     iter.next()         # Should return the same value as [val].
# @lc code=end

