#
# @lc app=leetcode id=894 lang=python3
#
# [894] All Possible Full Binary Trees
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
    # T: O(n * C(n)), n for cloning, C(n) := the nth Catalan Number https://math.stackexchange.com/questions/1994887
    # S: O(C(n)) because of intermediate recursion results
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        if (n & 1) == 0:
            # Impossible to build full binary trees with even number of nodes
            return []
        if n == 1:
            return [TreeNode(0)]

        def deep_copy(node: TreeNode) -> TreeNode:
            if not node:
                return None
            return TreeNode(0, deep_copy(node.left), deep_copy(node.right))

        res = []
        
        # Try different sizes of left and right subtrees.
        # IMPORTANT: because of root node, start i from 2 and left subtree size is i - 1
        for i in range(2, n + 1, 2):
            left_res = self.allPossibleFBT(i - 1)
            right_res = self.allPossibleFBT(n - i)
            for li, left_subtree in enumerate(left_res):
                for ri, right_subtree in enumerate(right_res):
                    node = TreeNode(0)
                    
                    # If deep copy not required (maybe in interview but not true in reality)
                    # just do the following:
                    # node.left = left_subtree
                    # node.right = right_subtree

                    # If we're using the last right res, then this will be the last time this left branch is used and can hence
                    # be shallow copied, otherwise the tree will have to be cloned
                    if ri == len(right_res) - 1:
                        node.left = left_subtree
                    else:
                        node.left = deep_copy(left_subtree)
                    
                    # If we're using the last left res, then this will be the last time this right branch is used and can hence
                    # be shallow copied, otherwise the tree will have to be cloned
                    if li == len(left_res) - 1:
                        node.right = right_subtree
                    else:
                        node.right = deep_copy(right_subtree)

                    res.append(node)
        return res

# @lc code=end

