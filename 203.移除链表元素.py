#
# @lc app=leetcode.cn id=203 lang=python3
#
# [203] 移除链表元素
#

from typing import Optional

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next: Optional[ListNode] = None

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # Linked list
    # T: O(n)
    # S: O(1)
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        dummy = ListNode(None)
        dummy.next = head
        cur = dummy

        # Check (and delete) `cur.next` instead of `cur`, 
        # because a singly linked list can't go backwards
        while cur.next is not None:
            if cur.next.val == val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        
        return dummy.next

# @lc code=end

