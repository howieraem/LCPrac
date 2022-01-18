#
# @lc app=leetcode.cn id=538 lang=python3
#
# [538] 把二叉搜索树转换为累加树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        """Reversed in-order traveral."""
        tmp = 0

        def inOrder(root):
            nonlocal tmp
            if root:
                inOrder(root.right)
                tmp += root.val
                root.val = tmp
                inOrder(root.left)
        
        inOrder(root)
        return root

# @lc code=end

