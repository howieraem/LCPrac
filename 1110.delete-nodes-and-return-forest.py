#
# @lc app=leetcode id=1110 lang=python3
#
# [1110] Delete Nodes And Return Forest
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
    # Post-order traversal
    # T: O(n + len(to_delete)), n := the no. of tree nodes
    # S: O(h + len(to_delete)), h := tree height
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        to_del = frozenset(to_delete)
        res = []
        root = self.helper(root, to_del, res)
        if root is not None:  # IMPORTANT: root is not to be deleted
            res.append(root)
        return res

    @staticmethod
    def helper(node: Optional[TreeNode], to_del: frozenset, res: List[TreeNode]) -> Optional[TreeNode]:
        if node is None:
            return None
        
        left = Solution.helper(node.left, to_del, res)
        right = Solution.helper(node.right, to_del, res)

        if node.val in to_del:
            if left is not None:
                res.append(left)
            if right is not None:
                res.append(right)
            return None
        
        # IMPORTANT: need to reassign children, e.g. if the node deleted is a leaf node
        node.left = left
        node.right = right
        
        return node

        
# @lc code=end

