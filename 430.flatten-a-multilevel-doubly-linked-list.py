#
# @lc app=leetcode id=430 lang=python3
#
# [430] Flatten a Multilevel Doubly Linked List
#
from typing import *

class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev: Optional[Node] = prev
        self.next: Optional[Node] = next
        self.child: Optional[Node] = child

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    # T: O(n)
    # S: O(1)
    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None:
            return head
        
        cur: Optional[Node] = head

        while cur is not None:
            # no child
            if cur.child is None:
                cur = cur.next
                continue
            
            # move to child branch end
            child = cur.child
            while child.next is not None:
                child = child.next

            # reconnect
            child.next = cur.next
            if cur.next is not None:
                cur.next.prev = child
            cur.next = cur.child
            cur.child.prev = cur
            cur.child = None

            cur = cur.next

        return head

# @lc code=end

