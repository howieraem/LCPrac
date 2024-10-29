#
# @lc app=leetcode.cn id=222 lang=python3
#
# [222] 完全二叉树的节点个数
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    '''
    # general solution for any binary tree
    def countNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        return self.countNodes(root.left) + self.countNodes(root.right) + 1
    '''

    # Using the properties of complete binary tree
    # T: O(log(n) ^ log(n))
    # S: O(log(n))
    def countNodes(self, root: TreeNode) -> int:
        if root is None:
            return 0
        left = self.getLevels(root.left)
        right = self.getLevels(root.right)
        if left == right:
            # Left subtree is a perfect binary tree
            # Right subtree is a complete binary tree
            return self.countNodes(root.right) + (1 << left)   # 2 ^ left
        
        # left > right
        # Left subtree is a complete binary tree (deeper)
        # Right subtree is a perfect binary tree
        return self.countNodes(root.left) + (1 << right)  # 2 ^ right

    # nodes in the last level are as far left as possible
    @staticmethod
    def getLevels(root):
        lvl = 0
        while root is not None:
            lvl += 1
            root = root.left
        return lvl

# @lc code=end

