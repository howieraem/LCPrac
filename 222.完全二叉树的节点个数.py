#
# @lc app=leetcode.cn id=222 lang=python3
#
# [222] 完全二叉树的节点个数
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    '''
    # general solution for any binary tree
    def countNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        return self.countNodes(root.left) + self.countNodes(root.right) + 1
    '''

    # Using the properties of complete binary tree
    def countNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        left = self.countLevels(root.left)
        right = self.countLevels(root.right)
        if left == right:
            # all levels full
            return self.countNodes(root.right) + (1 << left)
        return self.countNodes(root.left) + (1 << right)  # all levels full except last level

    @staticmethod
    def countLevels(root):
        lvl = 0
        while root:
            lvl += 1
            root = root.left
        return lvl

# @lc code=end

