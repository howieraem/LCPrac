#
# @lc app=leetcode id=106 lang=python3
#
# [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        self.inorder_val_idxs = {v: i for i, v in enumerate(inorder)}  # values are unique
        return self.helper(inorder, 0, len(inorder) - 1, postorder, 0, len(postorder) - 1)

    def helper(self, inorder, in_l, in_r, postorder, post_l, post_r) -> Optional[TreeNode]:
        if post_l > post_r:
            return None

        root_val = postorder[post_r]
        root_idx_in = self.inorder_val_idxs[root_val]
        left_subtree_size = root_idx_in - in_l
        
        root = TreeNode(root_val)

        # Note the symmetry of the post order indexes here and the pre order indexes in Q105 
        root.left = self.helper(inorder, in_l, root_idx_in - 1, 
                                postorder, post_l, post_l + left_subtree_size - 1)
        root.right = self.helper(inorder, root_idx_in + 1, in_r, 
                                 postorder, post_l + left_subtree_size, post_r - 1)
        return root


# @lc code=end

