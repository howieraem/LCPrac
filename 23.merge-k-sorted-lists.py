#
# @lc app=leetcode id=23 lang=python3
#
# [23] Merge k Sorted Lists
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
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        return self.partition(lists, 0, len(lists) - 1)

    def partition(self, lists: List[ListNode], l: int, r: int) -> ListNode:
        if l > r:
            return None
        elif l == r:
            return lists[l]
        m = (l + r) >> 1
        return self.merge(self.partition(lists, l, m), self.partition(lists, m + 1, r))

    def merge(self, a: ListNode, b: ListNode):
        if not a or not b:
            return a if a else b
        
        dummy = ListNode(0)
        cur = dummy
        cur_a = a
        cur_b = b

        while cur_a and cur_b:
            if cur_a.val < cur_b.val:
                cur.next = cur_a
                cur_a = cur_a.next
            else:
                cur.next = cur_b
                cur_b = cur_b.next
            cur = cur.next

        # Don't forget the remaining
        cur.next = cur_a if cur_a else cur_b

        return dummy.next
            

# @lc code=end

