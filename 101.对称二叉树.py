#
# @lc app=leetcode.cn id=101 lang=python3
#
# [101] 对称二叉树
#
from collections import deque

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        # recursive approach
        if not root:
            return True
        
        def dfs(left, right):
            if not left and not right:
                # base symmetric case
                return True
            if (not left or not right) or left.val != right.val:
                # prune asymmetric case branch
                return False
            return dfs(left.left, right.right) and dfs(left.right, right.left)  # note the symmetry here
        return dfs(root.left, root.right)

    def isSymmetric(self, root: TreeNode) -> bool:
        # iterative approach (similar idea to `Question [102]`)
        if not root or (not root.left and not root.right):
            return True
        q = deque()
        q.extend([root.left, root.right])
        while len(q):
            left = q.popleft()
            right = q.popleft()
            if not left and not right:
                continue
            if (not left or not right) or left.val != right.val:
                return False
            q.extend([left.left, right.right])
            q.extend([left.right, right.left])
        return True
        
# @lc code=end

