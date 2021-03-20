#
# @lc app=leetcode.cn id=124 lang=python3
#
# [124] 二叉树中的最大路径和
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    __slots__ = ['ans']

    def __init__(self):
        self.ans = float('-inf')

    def maxPathSum(self, root: TreeNode) -> int:
        def dfs(root):
            if not root:
                return 0
            left = dfs(root.left)
            right = dfs(root.right)
            self.ans = max(self.ans, root.val + left + right)
            # returning zero means discarding the current path which causes a decrease in sum
            return max(0, max(left, right) + root.val)
        dfs(root)
        return self.ans

# @lc code=end

