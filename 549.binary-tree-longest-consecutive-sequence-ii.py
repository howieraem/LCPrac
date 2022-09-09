#
# @lc app=leetcode id=549 lang=python3
#
# [549] Binary Tree Longest Consecutive Sequence II
#
from typing import *

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val: int = val
        self.left: Optional[TreeNode] = left
        self.right: Optional[TreeNode] = right

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # T: O(n)
    # S: O(n) worst (extremely imbalanced, linked list), recursion stack
    def longestConsecutive(self, root: Optional[TreeNode]) -> int:
        ans = 0

        def helper(node: Optional[TreeNode]) -> Tuple[int]:
            if not node:
                return (0, 0)
            
            left_res = helper(node.left)
            right_res = helper(node.right)
            
            n_inc = n_dec = 1
            if node.left:
                diff = node.val - node.left.val
                if diff == -1:
                    n_inc = left_res[0] + 1
                elif diff == 1:
                    n_dec = left_res[1] + 1
            if node.right:
                diff = node.val - node.right.val
                if diff == -1:
                    n_inc = max(n_inc, right_res[0] + 1)
                elif diff == 1:
                    n_dec = max(n_dec, right_res[1] + 1)
            
            # The path can span left and right subtrees
            nonlocal ans
            ans = max(ans, n_inc + n_dec - 1)
            return (n_inc, n_dec)

        helper(root)
        return ans

# @lc code=end

