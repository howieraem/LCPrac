#
# @lc app=leetcode id=776 lang=python3
#
# [776] Split BST
#
from typing import *

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    # T: O(n)
    # S: O(n) recursion stack
    def splitBST(self, root: Optional[TreeNode], target: int) -> List[Optional[TreeNode]]:
        if root is None:
            return [None, None]
        
        if root.val <= target:
            # split subtree rooted at root.right
            res_right = self.splitBST(root.right, target)
            root.right = res_right[0]
            return [root, res_right[1]]  # all values of subtree rooted at res[0] <= target
        else:
            # split subtree rooted at root.left
            res_left = self.splitBST(root.left, target)
            root.left = res_left[1]
            return [res_left[0], root]   # all values of subtree rooted at res[1] > target

# @lc code=end

