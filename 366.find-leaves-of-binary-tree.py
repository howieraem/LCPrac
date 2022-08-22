#
# @lc app=leetcode id=366 lang=python3
#
# [366] Find Leaves of Binary Tree
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
    # S: O(h)
    def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        self.helper(root, res)
        return res

    @staticmethod
    def helper(node: TreeNode, res: List[List[int]]) -> int:
        if node is None:
            return -1
        # node height: distance from the furthest leaf node in its subtrees
        height = max(Solution.helper(node.left, res), Solution.helper(node.right, res)) + 1
        if len(res) <= height:
            res.append([])
        res[height].append(node.val)
        return height
        
        
# @lc code=end

