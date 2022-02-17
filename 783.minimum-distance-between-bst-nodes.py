#
# @lc app=leetcode id=783 lang=python3
#
# [783] Minimum Distance Between BST Nodes
#
from typing import *

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
    # The result of inorder traversal of a BST is sorted.
    # The minimum distance must be the difference between
    # any two adjacent elements in the traversal result.
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        cur_min = 2**31 - 1
        pre = None

        def inorder(node: TreeNode):
            nonlocal cur_min, pre
            if not node:
                return cur_min
            
            inorder(node.left)

            if pre:
                cur_min = min(cur_min, node.val - pre.val)
            pre = node

            inorder(node.right)
            return cur_min

        return inorder(root)

# @lc code=end

