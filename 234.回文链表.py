#
# @lc app=leetcode.cn id=234 lang=python3
#
# [234] 回文链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        fast = head
        pre, cur = None, head
        while fast and fast.next:
            fast = fast.next.next   # twice faster than `cur`
            # Reverse list at slow pointer. 
            # Eventually first half will be reversed.
            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp
        if fast:    # odd number of nodes in linked list
            cur = cur.next
        while pre:
            # start comparing
            if pre.val != cur.val:
                return False
            pre = pre.next
            cur = cur.next
        return True


# @lc code=end

