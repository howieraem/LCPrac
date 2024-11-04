#
# @lc app=leetcode id=530 lang=python3
#
# [530] Minimum Absolute Difference in BST
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
    # Values of in-order traversal of BST is sorted
    # T: O(n)
    # S: O(h)
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        cur_min = float('inf')
        pre_val = -1

        def inorder(node: TreeNode):
            nonlocal cur_min, pre_val
            if node is None:
                # return cur_min
                return
            
            inorder(node.left)

            if pre_val != -1:
                cur_min = min(cur_min, node.val - pre_val)
            pre_val = node.val

            inorder(node.right)
            # return cur_min

        inorder(root)
        return cur_min
            

        
# @lc code=end

