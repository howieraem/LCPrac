#
# @lc app=leetcode id=1836 lang=python3
#
# [1836] Remove Duplicates From an Unsorted Linked List
#
from collections import defaultdict

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
    # S: O(n)
    def deleteDuplicatesUnsorted(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head

        val_cnts = defaultdict(int)
        cur = head
        while cur:
            val_cnts[cur.val] += 1
            cur = cur.next

        dummy = ListNode(0, head)
        pre = dummy
        cur = head
        while cur:
            if val_cnts[cur.val] > 1:
                # Disconnect the node if its value has duplicates
                pre.next = cur.next
                cur.next = None
                cur = pre  # IMPORTANT
            pre = cur
            cur = cur.next
        return dummy.next

# @lc code=end

