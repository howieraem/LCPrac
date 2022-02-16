#
# @lc app=leetcode id=889 lang=python3
#
# [889] Construct Binary Tree from Preorder and Postorder Traversal
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
    '''
    # Solution 1: Divide and conquer (with auxiliary map), similar to Q105 and Q106
    # T: O(n)
    # S: O(n)
    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        self.postorder_val_idxs = {v: i for i, v in enumerate(postorder)}
        return self.helper(preorder, 0, len(preorder) - 1, postorder, 0, len(postorder) - 1)

    def helper(self, preorder, pre_l, pre_r, postorder, post_l, post_r):
        if pre_l > pre_r:
            return None

        root = TreeNode(preorder[pre_l])
        if pre_l == pre_r:
            return root

        root_idx_post = self.postorder_val_idxs[preorder[pre_l + 1]]
        left_subtree_size = root_idx_post - post_l

        root.left = self.helper(preorder, pre_l + 1, pre_l + 1 + left_subtree_size, 
                                postorder, post_l, root_idx_post)
        root.right = self.helper(preorder, pre_l + 1 + left_subtree_size + 1, pre_r, 
                                 postorder, root_idx_post + 1, post_r - 1)
        return root
    '''

    # Solution 2: Pure recursion
    # T: O(n)
    # S: O(h) (worst case linked list, O(n))
    def __init__(self) -> None:
        self.pre_i = self.post_i = 0

    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        root = TreeNode(preorder[self.pre_i])
        self.pre_i += 1

        if root.val != postorder[self.post_i]:
            root.left = self.constructFromPrePost(preorder, postorder)
        if root.val != postorder[self.post_i]:
            root.right = self.constructFromPrePost(preorder, postorder)
        # The construction of (sub)tree is completed at this point when 
        # root.val == postorder(post_i) as the root is the final visited
        # note in postorder traversal.
        self.post_i += 1
        return root

# @lc code=end

