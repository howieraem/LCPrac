#
# @lc app=leetcode.cn id=61 lang=python3
#
# [61] 旋转链表
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head or not head.next or k <= 0: # list length < 1 or invalid k
            return head
        length = self.getListLength(head)
        k %= length
        if not k:
            return head
        fast = slow = head
        for _ in range(k):
            fast = fast.next
            # if not fast:
            #     fast = head
        while fast.next:
            fast = fast.next
            slow = slow.next
        n = new_head = slow.next
        slow.next = None
        while n.next:
            n = n.next
        n.next = head
        return new_head

    @staticmethod
    def getListLength(head: ListNode) -> int:
        l = 0
        n = head
        while n:
            l += 1
            n = n.next
        return l

# @lc code=end
def printLinkedList(head: ListNode):
    n = head
    while n:
        print(n.val)
        n = n.next

l = [1, 2]
n = ListNode(l[0])
n0 = n
for val in l[1:]:
    node = ListNode(val)
    n.next = node
    n = node
s = Solution()
n = s.rotateRight(n0, 2)
printLinkedList(n)
