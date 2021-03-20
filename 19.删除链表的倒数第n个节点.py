#
# @lc app=leetcode.cn id=19 lang=python3
#
# [19] 删除链表的倒数第N个节点
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        """
        Solution: fast and slow pointers. Difference between fast pointer index and
        slow pointer index is n-1. Thus, when fast pointer moves to the last node,
        the slow pointer will be at nth node from the end.
        """
        node = ListNode(None)
        node.next = head
        fast, slow = node, node
        for i in range(n):
            fast = fast.next
        while fast.next is not None:
            fast = fast.next
            slow = slow.next
        slow.next = slow.next.next  # break the linkage at nth from the end
        return node.next

    """
    original solution, space-wise comsumes extra memory for list copy:

    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        nodes = []
        nhead = node = head
        while node:
            nodes.append(node)
            node = node.next
        index = len(nodes) - n
        nodes.append(None)  # avoid IndexError if n=1
        if not index:
            return nhead.next
        nodes[index-1].next = nodes[index+1]
        return nhead
    """


# @lc code=end

