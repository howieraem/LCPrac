#
# @lc app=leetcode.cn id=24 lang=python3
#
# [24] 两两交换链表中的节点
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        """Solution: simple pointer swapping, no list copies."""
        dummy = ListNode(None)
        dummy.next = head
        curr = dummy
        while curr.next and curr.next.next:
            # note the order of next assignments
            a, b = curr.next, curr.next.next
            curr.next, a.next = b, b.next
            b.next = a
            curr = curr.next.next     # jump by a step size of 2
        return dummy.next
    """
    original solution:

    def swapPairs(self, head: ListNode) -> ListNode:
        if not head:
            return None
        if not head.next:
            return head
        node = head
        count = 0
        odd_nodes = []
        even_nodes = []
        while node:
            if count % 2:
                even_nodes.append(node)
            else:
                odd_nodes.append(node)
            node = node.next
            count += 1
        curr_node = None
        for on, en in zip(odd_nodes, even_nodes):
            if curr_node:
                curr_node.next = en
            curr_node = en
            curr_node.next = on
            curr_node = on
        curr_node.next = odd_nodes[-1]
        curr_node = curr_node.next
        curr_node.next = None
        return even_nodes[0]
    """

# @lc code=end
n1 = ListNode(1)
n2 = ListNode(2)
n3 = ListNode(3)
n1.next = n2
n2.next = n3
s = Solution()
n = s.swapPairs(n1)
while n:
    print(n.val)
    n = n.next
