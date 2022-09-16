#
# @lc app=leetcode id=951 lang=python3
#
# [951] Flip Equivalent Binary Trees
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
    # T: O(n) if each tree will have unique node values (problem constraint), otherwise O(n ^ 2)
    # S: O(n) worst
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        if root1 is None and root2 is None:
            return True
        if root1 is None or root2 is None or root1.val != root2.val:
            return False
        return (self.flipEquiv(root1.left, root2.left) and self.flipEquiv(root1.right, root2.right)) or \
                (self.flipEquiv(root1.left, root2.right) and self.flipEquiv(root1.right, root2.left))

# @lc code=end

