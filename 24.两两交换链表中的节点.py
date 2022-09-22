#
# @lc app=leetcode.cn id=24 lang=python3
#
# [24] 两两交换链表中的节点
#

class ListNode:
    def __init__(self, x=0):
        self.val = x
        self.next: ListNode = None

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        """Solution: simple pointer swapping, no list copies."""
        dummy = ListNode()
        dummy.next = head
        curr = dummy
        while curr.next and curr.next.next:
            # note the order of next assignments
            a, b = curr.next, curr.next.next
            curr.next, a.next = b, b.next
            b.next = a
            curr = curr.next.next     # jump by a step size of 2
        return dummy.next

# @lc code=end
# n1 = ListNode(1)
# n2 = ListNode(2)
# n3 = ListNode(3)
# n1.next = n2
# n2.next = n3
# s = Solution()
# n = s.swapPairs(n1)
# while n:
#     print(n.val)
#     n = n.next
