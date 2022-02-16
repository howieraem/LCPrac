#
# @lc app=leetcode id=99 lang=python3
#
# [99] Recover Binary Search Tree
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
    # T: O(n)
    # S: O(n) recursion stack
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.node1 = None
        self.node2 = None

        # The last visited node in inorder traversal. It is initialized to 
        # INT_MIN so that the logic in inorder traversal is simpler.
        self.pre = TreeNode(-2 ** 31)

        self.inorder(root)

        # Swap node values
        self.node1.val, self.node2.val = self.node2.val, self.node1.val

    # Remember, the result of the inorder traversal of a correct BST is sorted.
    # Thus, we can do an inorder traversal and find the only 2 node values that 
    # are greater than their next values.
    def inorder(self, node: Optional[TreeNode]):
        if not node:
            return
        self.inorder(node.left)
        
        # Example: original traversal result [6, 3, 4, 5, 2]
        #   - Check if the value previously visited is greater
        #   - If node1 is not yet found, set node1 to that previous node (val = 6)
        #   - If node1 is found, set node2 to the current node (val = 2)
        # if not self.node1 and node.val < self.pre.val:
        #     self.node1 = self.pre
        # if self.node1 and node.val < self.pre.val:
        #     self.node2 = node
        if node.val < self.pre.val:
            if not self.node1:
                self.node1 = self.pre
            self.node2 = node

        # The visited node
        self.pre = node

        self.inorder(node.right)
        
# @lc code=end

