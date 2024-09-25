#
# @lc app=leetcode id=445 lang=python3
#
# [445] Add Two Numbers II
#
from typing import Optional

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
    # Solution without stack and without reversing input lists
    # T: O(len(l1) + len(l2))
    # S: O(len(l1) + len(l2))
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # Get list sizes
        s1 = 0
        cur = l1
        while cur is not None:
            s1 += 1
            cur = cur.next
        s2 = 0
        cur = l2
        while cur is not None:
            s2 += 1
            cur = cur.next
        
        if s1 < s2:  # make s1 the longer list
            s1, s2 = s2, s1
            l1, l2 = l2, l1

        # Build list from tail
        cur = None
        for _ in range(s1 - s2):
            cur = ListNode(l1.val, cur)
            l1 = l1.next
        for _ in range(s2):
            cur = ListNode(l1.val + l2.val, cur)
            l1 = l1.next
            l2 = l2.next

        # reverse newly created list and handle carry
        carry = 0
        pre = None
        while cur is not None:
            v = cur.val + carry
            if v >= 10:
                v -= 10
                carry = 1
            else:
                carry = 0
            cur.val = v

            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp

        # don't forget the final carry
        if carry > 0:
            pre = ListNode(carry, pre)
        return pre

# @lc code=end

