#
# @lc app=leetcode.cn id=98 lang=python3
#
# [98] 验证二叉搜索树
#

# @lc code=start
# Definition for a binary tree node.
import functools

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        
        @functools.lru_cache(None)
        def checkNode(node, lower=float('-inf'), upper=float('inf')):
            if not node:
                return True
            val = node.val
            if val <= lower or val >= upper:
                return False
            return (
                checkNode(node.right, lower=val, upper=upper) and 
                checkNode(node.left, lower=lower, upper=val)
            )
        return checkNode(root)

# @lc code=end
