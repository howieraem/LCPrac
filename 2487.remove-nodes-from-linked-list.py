from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    # Linked list reversal, simulating mono-stack without O(n) space
    # T: O(n)
    # S: O(1)
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head

        # Reverse the list
        pre = None
        cur = head
        while cur is not None:
            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp

        # Now remove next smaller nodes, 
        # and reverse the list back
        cur = pre.next
        pre.next = None
        while cur is not None:
            tmp = cur.next
            if cur.val >= pre.val:
                cur.next = pre
                pre = cur
            cur = tmp

        return pre
