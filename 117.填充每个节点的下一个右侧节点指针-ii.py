#
# @lc app=leetcode.cn id=117 lang=python3
#
# [117] 填充每个节点的下一个右侧节点指针 II
#
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    """
    # Recursive solution
    def connect(self, root: 'Node') -> 'Node':
        if not root or (not root.left and not root.right):
            return root
        if root.left:
            if root.right:
                root.left.next = root.right
                # since the right subtree is built first, no need to find the right most leaf node here
                if root.next:
                    root.right.next = root.next.left if root.next.left else root.next.right
            else:
                if root.next:
                    tmp = root.next
                    while tmp.next and not tmp.left and not tmp.right:
                        tmp = tmp.next
                    root.left.next = tmp.left if tmp.left else tmp.right
        if root.right:
            if root.next:
                tmp = root.next
                while tmp.next and not tmp.left and not tmp.right:
                    tmp = tmp.next
                root.right.next = tmp.left if tmp.left else tmp.right
        # build the right subtree first
        self.connect(root.right)
        self.connect(root.left)
        return root
    """

    def connect(self, root: 'Node') -> 'Node':
        """Iterative solution: treats each level of the tree as a linked list."""
        head = root
        while head:
            lvl = Node()    # dummy node
            tail = lvl
            while head:  # if head becomes `None`, then it has reached the right most
                if head.left:
                    tail.next = head.left
                    tail = tail.next
                if head.right:
                    tail.next = head.right
                    tail = tail.next
                head = head.next
            head = lvl.next  # move head to the first element of the level just linked
        return root
        
# @lc code=end

