#
# @lc app=leetcode.cn id=92 lang=python3
#
# [92] 反转链表 II
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        """Original solution: multiple pointers"""
        # init new linked list
        dummy = ListNode(None)
        dummy.next = head
        
        # move to position m
        preslow = dummy
        for _ in range(m-1):    # because of dummy, range starts from 0
            preslow = preslow.next

        while m < n:
            # move pointers
            prefast = slow = preslow.next
            ptr = m
            while ptr != n-1:
                prefast = prefast.next
                ptr += 1
            fast = prefast.next

            # perform swap
            tmp = fast.next
            prefast.next = slow
            preslow.next = fast
            fast.next = slow.next
            slow.next = tmp

            # prepare for next swap
            m += 1
            preslow = preslow.next
            n -= 1
        return dummy.next

    
    def reverseBetween(self, head, m, n):
        """Simpler solution."""
        if m == n:
            return head

        dummy = ListNode(None)
        dummy.next = head
        
        pre_mth = nth = dummy
        for _ in range(m - 1):
            pre_mth = pre_mth.next
        for _ in range(n):
            nth = nth.next
        
        mth, nth_nxt = pre_mth.next, nth.next
        prev = mth
        curr = prev.next
        i = n - m
        while i:    # or `while curr is not nth_nxt:`
            # swap every pair of nodes
            tmp = curr.next
            curr.next = prev
            prev = curr
            curr = tmp
            i -= 1
        
        # final adjustment
        pre_mth.next = nth
        mth.next = nth_nxt
        return dummy.next


# def printList(head: ListNode) -> None:
#     n = head
#     string = ''
#     while n.next:
#         string += str(n.val) + '->'
#         n = n.next
#     string += str(n.val)
#     print(string)
        

# # @lc code=end
# l = [1,2,3,4,5,6]
# ns = [ListNode(v) for v in l]
# for i in range(1, len(ns)):
#     ns[i-1].next = ns[i]

# s = Solution()
# head = s.reverseBetween(ns[0], 2, 5)
# printList(head)
