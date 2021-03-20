#
# @lc app=leetcode.cn id=86 lang=python3
#
# [86] 分隔链表
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        # 1. find the first element x' greater than x
        # 2. shift all elements on the right of x' which are less than x to the left of x'
        if not head or not head.next:
            return head
        dummy = ListNode(None)
        dummy.next = head
        slow = dummy
        fast = dummy.next
        partition_node, pre_partition_node = None, None
        while fast:
            if partition_node:
                if fast.val < x:
                    pre_partition_node.next = fast
                    tmp = fast.next
                    fast.next = partition_node
                    slow.next = tmp
                    fast = tmp
                    pre_partition_node = pre_partition_node.next
                    continue
            if fast.val >= x and not partition_node:
                partition_node = fast
                pre_partition_node = slow
            fast = fast.next
            slow = slow.next
        return dummy.next


def printList(head: ListNode) -> None:
    n = head
    string = ''
    while n.next:
        string += str(n.val) + '->'
        n = n.next
    string += str(n.val)
    print(string)

# @lc code=end
vs = [4, 1, 3, 2, 1, 5]

l = [ListNode(v) for v in vs]
for i in range(len(l)-1):
    n, nn = l[i:i+2]
    n.next = nn
# printList(l[0])

s = Solution()
nd = s.partition(l[0], 3)
printList(nd)
