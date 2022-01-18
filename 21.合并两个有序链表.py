#
# @lc app=leetcode.cn id=21 lang=python3
#
# [21] 合并两个有序链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode(None)
        prev = dummy
        while l1 and l2:
            if l1.val <= l2.val:
                prev.next = l1
                l1 = l1.next
            else:
                prev.next = l2
                l2 = l2.next            
            prev = prev.next

        # 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        prev.next = l1 if l1 is not None else l2
        
        return dummy.next

# def printList(head: ListNode) -> None:
#     if not head:
#         return
#     prev = head
#     string = ''
#     while prev.next:
#         string += str(prev.val) + '->'
#         prev = prev.next
#     string += str(prev.val)
#     print(string)
        
# @lc code=end
# l1 = [7]
# l2 = [1, 4, 10]

# l1 = [ListNode(v) for v in l1]
# l2 = [ListNode(v) for v in l2]
# for i in range(len(l1)-1):
#     l1[i].next = l1[i+1]
# for i in range(len(l2)-1):
#     l2[i].next = l2[i+1]
# printList(l1[0])
# printList(l2[0])

# prev = Solution().mergeTwoLists(l1[0], l2[0])
# printList(prev)
