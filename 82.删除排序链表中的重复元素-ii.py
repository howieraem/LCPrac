#
# @lc app=leetcode.cn id=82 lang=python3
#
# [82] 删除排序链表中的重复元素 II
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            # list length less than 2, no repetition
            return head
        dummy = ListNode(None)
        dummy.next = head
        slow = dummy
        fast = dummy.next
        while fast:
            if fast.next and fast.next.val == fast.val:
                tmp = fast.val
                while fast and tmp == fast.val:
                    fast = fast.next
            else:
                slow.next = fast    # if the first node is repeated, this step overwrites it too
                slow = fast
                fast = fast.next
        slow.next = fast    # don't forget the last one
        return dummy.next

# def printList(head: ListNode) -> None:
#     n = head
#     string = ''
#     while n.next:
#         string += str(n.val) + '->'
#         n = n.next
#     string += str(n.val)
#     print(string)

# @lc code=end
# l = [ListNode(1),ListNode(1),ListNode(3),ListNode(3),ListNode(4),ListNode(4),ListNode(5)]
# for i in range(len(l)-1):
#     n, nn = l[i:i+2]
#     n.next = nn
# printList(l[0])

# s = Solution()
# nd = s.deleteDuplicates(l[0])
# printList(nd)
