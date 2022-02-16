#
# @lc app=leetcode id=107 lang=python3
#
# [107] Binary Tree Level Order Traversal II
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
    # Trivial solution: BFS level-order traversal (Q102) -> reverse levels in result container
    # Non-trivial DFS solution: find the depth -> pre-allocate space -> assign level result according to depth
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        depth = self.get_depth(root)
        res = [[] for _ in range(depth)]
        self.helper(root, depth - 1, res)
        return res

    def helper(self, node: TreeNode, lvl: int, res: List[List[int]]):
        if not node:
            return
        res[lvl].append(node.val)
        lvl -= 1
        self.helper(node.left, lvl, res)
        self.helper(node.right, lvl, res)

    def get_depth(self, root: TreeNode):
        if not root:
            return 0
        return max(self.get_depth(root.left), self.get_depth(root.right)) + 1

# @lc code=end

