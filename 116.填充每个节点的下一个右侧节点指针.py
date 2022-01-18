#
# @lc app=leetcode.cn id=116 lang=python3
#
# [116] 填充每个节点的下一个右侧节点指针
#

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
        if not root:
            return   # None
        if root.left:
            root.left.next = root.right
            if root.next:
                root.right.next = root.next.left
        self.connect(root.left)
        self.connect(root.right)
        return root
    """

    def connect(self, root: 'Node') -> 'Node':
        """Iterative solution"""
        pre = root
        while pre:
            cur = pre
            while cur:
                if cur.left: 
                    cur.left.next = cur.right
                if cur.right and cur.next: 
                    cur.right.next = cur.next.left
                cur = cur.next
            pre = pre.left
        return root

        
# @lc code=end
# n1 = Node(1)
# n2 = Node(2)
# n3 = Node(3)
# n4 = Node(4)
# n5 = Node(5)
# n6 = Node(6)
# n7 = Node(7)
# n1.left, n1.right = n2, n3
# n2.left, n2.right = n4, n5
# n3.left, n3.right = n6, n7

# s = Solution()
# s.connect(n1)
# print(n4.next.val, n5.next.val, n6.next.val, n7.next)
