#
# @lc app=leetcode.cn id=148 lang=python3
#
# [148] 排序链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        """Recursive solution, which utilizes stack and 
        might not meet the O(1) space requirement."""
        if not head or not head.next:
            return head
        slow = head
        fast = head.next
        while fast and fast.next:
            # to get the mid point, fast is twice as fast
            fast = fast.next.next
            slow = slow.next
        # cut the link
        mid = slow.next
        slow.next = None

        # recursively sort (and then merge)
        left, right = self.sortList(head), self.sortList(mid)
        dummy = ListNode(None)
        curr = dummy
        while left and right:   # both not null
            if left.val < right.val:
                curr.next = left
                left = left.next
            else:
                curr.next = right
                right = right.next
            curr = curr.next
        curr.next = left if left else right
        return dummy.next

    def sortList(self, head: ListNode) -> ListNode:
        """Prevents recursion. Merge in a bottom-top manner: 
        two by two, then four by four, and so on."""
        curr, length, merge_size = head, 0, 1
        while curr: 
            curr, length = curr.next, length + 1
        dummy = ListNode(None)
        dummy.next = head
        # merge the list in different intv.
        while merge_size < length:
            pre, curr = dummy, dummy.next
            while curr:
                # get the two merge head `h1`, `h2`
                h1, i = curr, merge_size
                while i and curr: 
                    curr, i = curr.next, i - 1
                if i: 
                    break  # no need to merge because `h2` is None.
                h2, i = curr, merge_size
                while i and curr: 
                    curr, i = curr.next, i - 1
                c1, c2 = merge_size, merge_size - i # the `c2`: length of `h2` can be small than the `intv`.
                
                # merge `h1` and `h2`.
                while c1 and c2:
                    if h1.val < h2.val: 
                        pre.next, h1, c1 = h1, h1.next, c1 - 1
                    else: 
                        pre.next, h2, c2 = h2, h2.next, c2 - 1
                    pre = pre.next
                pre.next = h1 if c1 else h2
                while c1 > 0 or c2 > 0: 
                    pre, c1, c2 = pre.next, c1 - 1, c2 - 1
                pre.next = curr 
            merge_size *= 2
        return dummy.next


# @lc code=end

