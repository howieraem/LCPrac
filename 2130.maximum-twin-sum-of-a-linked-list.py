#
# @lc app=leetcode id=2130 lang=python3
#
# [2130] Maximum Twin Sum of a Linked List
#
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next: Optional[ListNode] = next

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # Fast slow pointers + list reversal
    # T: O(n)
    # S: O(1)
    def pairSum(self, head: Optional[ListNode]) -> int:
        if head is None:
            return 0
        if head.next is None:
            return head.val

        # find midpoint
        fast = head
        slow = head
        while fast.next.next is not None:
            fast = fast.next.next
            slow = slow.next

        # reverse list from midpoint (slow) to tail
        pre = None
        while slow is not None:
            tmp = slow.next
            slow.next = pre
            pre = slow
            slow = tmp

        # Now pre is the head of the right half reversed list
        ans = float('-inf')
        while head is not None and pre is not None:
            ans = max(ans, head.val + pre.val)
            pre = pre.next
            head = head.next

        return ans

# @lc code=end

