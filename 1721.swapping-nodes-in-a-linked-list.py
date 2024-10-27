#
# @lc app=leetcode id=1721 lang=python3
#
# [1721] Swapping Nodes in a Linked List
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
    # T: O(n)
    # S: O(1)
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head is None or head.next is None or k < 1:
            return head

        # shift k-1 times
        left_k = head
        while k != 1 and left_k is not None:
            left_k = left_k.next
            k -= 1
        if left_k is None:  # index out of range
            return head

        # shift len(list)-(k-1) times
        right_k = head
        cur = left_k
        while cur.next is not None:
            right_k = right_k.next
            cur = cur.next
        
        left_k.val, right_k.val = right_k.val, left_k.val
        return head

# @lc code=end

