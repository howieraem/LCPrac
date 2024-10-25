#
# @lc app=leetcode id=341 lang=python3
#
# [341] Flatten Nested List Iterator
#
from typing import *

class NestedInteger:
   def isInteger(self) -> bool:
       """
       @return True if this NestedInteger holds a single integer, rather than a nested list.
       """
       pass

   def getInteger(self) -> int:
       """
       @return the single integer that this NestedInteger holds, if it holds a single integer
       Return None if this NestedInteger holds a nested list
       """
       pass

   def getList(self) -> List[NestedInteger]:
       """
       @return the nested list that this NestedInteger holds, if it holds a nested list
       Return None if this NestedInteger holds a single integer
       """
       pass

# @lc code=start
# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """

# Why stack: consider the nested lists as calculator expressions 
# or parentheses matching problems. There might exist cases like 
# [x1, [x2, x3, [x4, x5], x6], x7].
# S: O(n)
class NestedIterator:
    # T: O(n)
    def __init__(self, nestedList: List[NestedInteger]):
        self.stack: List[NestedInteger] = []
        # stack is LIFO, so iterate from the back
        for i in range(len(nestedList) - 1, -1, -1):
            self.stack.append(nestedList[i])
    
    # T: O(1)
    def next(self) -> int:
        if self.hasNext():
            return self.stack.pop().getInteger()
        return None

    # T: O(n)
    def hasNext(self) -> bool:
        while len(self.stack) > 0 and not self.stack[-1].isInteger():
            lst = self.stack.pop().getList()
            # stack is LIFO, so iterate from the back
            for i in range(len(lst) - 1, -1, -1):
                self.stack.append(lst[i])
        return len(self.stack) > 0

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
# @lc code=end

