#
# @lc app=leetcode id=105 lang=python3
#
# [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    # T: O(n)
    # S: O(n) dict and recursion stack
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        self.inorder_val_idxs = {v: i for i, v in enumerate(inorder)}  # values are unique
        return self.helper(preorder, 0, len(preorder) - 1, inorder, 0, len(inorder) - 1)

    def helper(self, preorder, pre_l, pre_r, inorder, in_l, in_r) -> Optional[TreeNode]:
        if pre_l > pre_r:
            return None

        root_val = preorder[pre_l]
        # root_idx_in = 0
        # for i in range(in_l, in_r + 1):
        #     if inorder[i] == root_val:
        #         root_idx_in = i
        #         break
        root_idx_in = self.inorder_val_idxs[root_val]
        left_subtree_size = root_idx_in - in_l
        
        root = TreeNode(root_val)
        root.left = self.helper(preorder, pre_l + 1, pre_l + left_subtree_size, 
                                inorder, in_l, root_idx_in - 1)
        root.right = self.helper(preorder, pre_l + left_subtree_size + 1, pre_r, 
                                 inorder, root_idx_in + 1, in_r)
        return root

# @lc code=end

