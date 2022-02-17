#
# @lc app=leetcode id=328 lang=python3
#
# [328] Odd Even Linked List
#
from typing import *

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next: ListNode = next

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        odd: ListNode = head
        even: ListNode = head.next
        even_head = even

        while even and even.next:
            odd.next = odd.next.next
            even.next = even.next.next

            odd = odd.next
            even = even.next
        
        odd.next = even_head    # connect the even list to the odd list
        return head

# @lc code=end

