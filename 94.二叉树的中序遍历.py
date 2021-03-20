#
# @lc app=leetcode.cn id=94 lang=python3
#
# [94] 二叉树的中序遍历
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        """Recursive approach"""
        if not root:
            return []
        res = []
        def inorder(node):
            if node.left is not None:
                inorder(node.left)
            res.append(node.val)
            if node.right is not None:
                inorder(node.right)
        inorder(root)
        return res

    def inorderTraversal(self, root: TreeNode) -> List[int]:
        """Iterative approach with a stack (FILO or LIFO)"""
        if not root:
            return []
        stack, res = [root], []
        while stack:
            i = stack.pop()
            if isinstance(i, TreeNode):
                stack.extend([i.right, i.val, i.left])  # note the order of nodes in extension list
            else:   # elif isinstance(i, int):
                res.append(i)
        return res

# @lc code=end

