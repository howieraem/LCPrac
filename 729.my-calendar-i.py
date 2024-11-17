#
# @lc app=leetcode id=729 lang=python3
#
# [729] My Calendar I
#
from typing import *

# @lc code=start
# binary search tree (without self balancing)
# segment tree non-array implementation?
class Node:
    def __init__(self, start, end):
        self.start = start
        self.end = end
        self.left: Optional[Node] = None
        self.right: Optional[Node] = None

# S: O(n)
class MyCalendar:
    # T: O(1)
    def __init__(self):
        self.root: Optional[Node] = None

    @staticmethod
    def dfs(node: Node, start: int, end: int) -> bool:
        if start >= node.end:   # new interval is on the right of current interval in tree
            if node.right is not None:
                return MyCalendar.dfs(node.right, start, end)
            else:
                node.right = Node(start, end)
                return True
        elif end <= node.start:  # new interval is on the left of current interval in tree
            if node.left is not None:
                return MyCalendar.dfs(node.left, start, end)
            else:
                node.left = Node(start, end)
                return True
        else:
            # start < node.end or end > node.start, has overlap
            return False

    # T: O(log(n)) avg, O(n) worst without self balancing
    def book(self, start: int, end: int) -> bool:
        if self.root is None:
            self.root = Node(start, end)
            return True
        
        return self.dfs(self.root, start, end)


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)
# @lc code=end

