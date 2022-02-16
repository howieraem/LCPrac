#
# @lc app=leetcode id=235 lang=python3
#
# [235] Lowest Common Ancestor of a Binary Search Tree
#

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
    # Property of BST: All values in the left subtree are less than the root value, and
    # all values in the right subtree are greater than the root value
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        ancester = root
        while True:
            if p.val > ancester.val and q.val > ancester.val:
                ancester = ancester.right
            elif p.val < ancester.val and q.val < ancester.val:
                ancester = ancester.left
            else:
                # At this point, p and q are on different sides,
                # the current node is the lowest common ancester 
                return ancester

# @lc code=end

