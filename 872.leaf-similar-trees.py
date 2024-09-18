#
# @lc app=leetcode id=872 lang=python3
#
# [872] Leaf-Similar Trees
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
    # T: O(n), n := the total number of nodes
    # S: O(n) 
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def helper(root: Optional[TreeNode], leaves: List[int]) -> None:
            if root is None:
                return
            if root.left is None and root.right is None:
                # leaf node
                leaves.append(root.val)
            helper(root.left, leaves)
            helper(root.right, leaves)
        
        leaves1 = []
        leaves2 = []
        helper(root1, leaves1)
        helper(root2, leaves2)
        return leaves1 == leaves2


# @lc code=end

