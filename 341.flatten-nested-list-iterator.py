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

class NestedIterator:
    def __init__(self, nestedList: List[NestedInteger]):
        self.stack: List[NestedInteger] = []
        for i in range(len(nestedList) - 1, -1, -1):
            self.stack.append(nestedList[i])
    
    def next(self) -> int:
        if self.hasNext():
            return self.stack.pop().getInteger()
        return None

    def hasNext(self) -> bool:
        while len(self.stack) and not self.stack[-1].isInteger():
            lst = self.stack.pop().getList()
            for i in range(len(lst) - 1, -1, -1):
                self.stack.append(lst[i])
        return bool(len(self.stack))

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
# @lc code=end

