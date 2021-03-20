#
# @lc app=leetcode.cn id=99 lang=python3
#
# [99] 恢复二叉搜索树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.x = None
        self.y = None
        self.pre = None

        def dfs(root):
            # In-order traversal
            if not root:
                return
            dfs(root.left)
            
            if self.pre:
                if root.val < self.pre.val:
                    self.y = root
                    if not self.x:
                        self.x = self.pre
            self.pre = root
            
            dfs(root.right)

        dfs(root)
        if self.x and self.y:
            self.x.val, self.y.val = self.y.val, self.x.val

# @lc code=end

