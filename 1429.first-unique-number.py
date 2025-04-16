#
# @lc app=leetcode id=1429 lang=python3
#
# [1429] First Unique Number
#
from typing import *

# @lc code=start
class Node:
    def __init__(self, v=0):
        self.pre: Node = None
        self.nxt: Node = None
        self.v = v

# Hash Map + Doubly Linked List
# S: O(n)
class FirstUnique:
    # T: O(n)
    def __init__(self, nums: List[int]):
        self.val2node: Dict[int, Node] = {}

        # doubly linked list
        self.head = Node()
        self.tail = Node()
        self.head.nxt = self.tail
        self.tail.pre = self.head

        for x in nums:
            self.add(x)

    # T: O(1)
    def showFirstUnique(self) -> int:
        node = self.head.nxt
        # print(node.v)
        return -1 if node is self.tail else node.v

    # T: O(1)
    def add(self, value: int) -> None:
        node = self.val2node.get(value, None)
        if node is None:
            node = Node(value)
            self.val2node[value] = node
            self.__add_to_tail(node)
        else:
            if node.pre is None or node.nxt is None:
                # value is not unique
                return
            node.pre.nxt = node.nxt
            node.nxt.pre = node.pre
            node.pre = None
            node.nxt = None

    def __add_to_tail(self, node: Node):
        tail = self.tail
        if tail is None or tail.pre is None:
            return
        node.nxt = tail
        node.pre = tail.pre
        tail.pre.nxt = node
        tail.pre = node


# Your FirstUnique object will be instantiated and called as such:
# obj = FirstUnique(nums)
# param_1 = obj.showFirstUnique()
# obj.add(value)
# @lc code=end

