#
# @lc app=leetcode id=1676 lang=python3
#
# [1676] Lowest Common Ancestor of a Binary Tree IV
#
from typing import List

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # Binary Tree + DFS
    # T: O(n)
    # S: O(n)
    def lowestCommonAncestor(self, root: 'TreeNode', nodes: 'List[TreeNode]') -> 'TreeNode':
        vals = set(node.val for node in nodes)

        def helper(node: 'TreeNode'):
            if node is None or node.val in vals:
                return node
            left = helper(node.left)
            right = helper(node.right)
            if left is not None and right is not None:
                return node

            return left if left is not None else right

        return helper(root)


# @lc code=end

