#
# @lc app=leetcode.cn id=114 lang=python3
#
# [114] 二叉树展开为链表
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """

        def dfs(root):
            """Preorder traversal:
                visit(root)
                dfs(root.left)
                dfs(root.right)
            """
            if not root:
                return None
            left, right = root.left, root.right
            left_list = dfs(left)
            right_list = dfs(right)
            root.left = None
            if left_list:
                root.right = left_list
                node = root.right
                while node.right:
                    node = node.right
                node.right = right_list
            else:
                root.right = right_list
            return root
        return dfs(root)

    def flatten(self, root: TreeNode) -> None:
        """Solution without recursion."""
        curr = root
        while curr:
            if curr.left:
                predecessor = nxt = curr.left
                while predecessor.right:
                    predecessor = predecessor.right
                predecessor.right = curr.right

                # turn tree node into list node
                curr.left = None
                curr.right = nxt
            curr = curr.right

# def printList(n):
#     while n:
#         print(n.val)
#         n = n.right
        
# @lc code=end
# n1 = TreeNode(1)
# n2 = TreeNode(2)
# n3 = TreeNode(3)
# n4 = TreeNode(4)
# n5 = TreeNode(5)
# n6 = TreeNode(6)
# n1.left, n1.right = n2, n5
# n2.left, n2.right = n3, n4
# n5.right = n6

# s = Solution()
# s.flatten(None)
# printList(n1)
