#
# @lc app=leetcode id=1660 lang=python3
#
# [1660] Correct a Binary Tree
#

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self) -> None:
        self.vis = set()

    # Pre-order traversal and hash set
    # T: O(n)
    # S: O(n)
    def correctBinaryTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        if root.right and root.right.val in self.vis:
            return None
        self.vis.add(root.val)
        root.right = self.correctBinaryTree(root.right)
        root.left = self.correctBinaryTree(root.left)
        return root
        
# @lc code=end

