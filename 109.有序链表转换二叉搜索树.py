#
# @lc app=leetcode.cn id=109 lang=python3
#
# [109] 有序链表转换二叉搜索树
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        """Divide and conquer: time O(Nlog(N)), space O(log(N))."""
        if not head:
            return None
        if not head.next:
            return TreeNode(head.val)
        pre = None
        slow = fast = head
        while fast and fast.next:
            # `fast` index is twice of `slow` index,
            # so when looping is done slow will be
            # at the middle (median) of linked list.
            # This can be slow if the linked list 
            # is long. One may make a copy with an 
            # array (list) instead.
            pre = slow
            slow = slow.next
            fast = fast.next.next
        pre.next = None     # slice the linked list for building the left subtree
        root = TreeNode(slow.val)
        root.left = self.sortedListToBST(head)  # left subtree
        root.right = self.sortedListToBST(slow.next)    # right subtree
        return root

    def sortedListToBST(self, head: ListNode) -> TreeNode:
        """The linked list is the inorder traversal of the corresponding tree.
        Thus, the solution can be optimized to O(N) for time complexity."""
        length = 0
        ptr = head
        while ptr:
            length += 1
            ptr = ptr.next

        def buildTree(left, right):
            if left > right:
                return None
            mid = (left+right+1) >> 1
            root = TreeNode()   # note that no value is given yet
            root.left = buildTree(left, mid-1)
            nonlocal head
            root.val = head.val
            head = head.next
            root.right = buildTree(mid+1, right)
            return root

        return buildTree(0, length-1)


        
# @lc code=end

