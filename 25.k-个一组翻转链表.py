#
# @lc app=leetcode.cn id=25 lang=python3
#
# [25] K 个一组翻转链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        dummy = ListNode(None)
        dummy.next = head
        pre = end = dummy
        while end.next:
            for _ in range(k):
                end = end.next
                if not end:
                    # the remaining number of nodes less than k
                    return dummy.next
            start, tmp = pre.next, end.next
            end.next = None     # cut
            pre.next = self.reverse(start)
            start.next = tmp
            pre = start
            end = pre
        return dummy.next

    @staticmethod
    def reverse(head: ListNode):
        pre, cur = None, head
        while cur:
            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp
        return pre

# @lc code=end

