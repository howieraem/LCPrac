#
# @lc app=leetcode id=25 lang=python3
#
# [25] Reverse Nodes in k-Group
#
from typing import *

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(next=head)
        pre = dummy
        group_begin = None
        group_end = dummy

        while group_end:
            for _ in range(k):
                group_end = group_end.next
                if not group_end:
                    return dummy.next

            group_begin = pre.next
            after = group_end.next

            group_end.next = None

            # self.reverse(group_begin)
            # pre.next = group_end
            pre.next = self.reverse(group_begin)
            
            group_begin.next = after

            pre = group_begin
            group_end = group_begin
        
        return dummy.next

    @staticmethod
    def reverse(head: ListNode):
        pre = None
        cur = head

        while cur:
            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp

        return pre

# @lc code=end

