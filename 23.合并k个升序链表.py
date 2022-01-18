#
# @lc app=leetcode.cn id=23 lang=python3
#
# [23] 合并K个升序链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import heapq

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        """Solution with priority queue, or heap sort. Time complexity 
        O(k*n*log(k)) because operations in heap take O(log(k)), and 
        space complexity O(k).
        """
        if not lists or (len(lists) == 1 and not lists[0]):
            return None
        # build a min heap
        heap = []
        for node in lists:
            while node:
                heapq.heappush(heap, node.val)
                node = node.next

        # do heap sort
        dummy = ListNode(None)
        n = dummy
        while heap:
            node = ListNode(heapq.heappop(heap))    # each time the mininum is popped
            n.next = node
            n = node
        return dummy.next

    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        """Solution with divide & conquer and code in `[21] merge two sorted linked list`.
        Lists will be merged in pairs recursively. Time complexity O(k*n*log(k)), space
        complexity O(log(k))."""
        def helper(lists, left, right):
            if left > right:
                return
            elif left == right:
                return lists[left]
            mid = (left+right) >> 1
            return self.mergeTwoLists(helper(lists, left, mid), helper(lists, mid+1, right))
        return helper(lists, 0, len(lists)-1)

    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        cur1, cur2 = l1, l2
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

# @lc code=end

