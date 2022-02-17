#
# @lc app=leetcode id=863 lang=python3
#
# [863] All Nodes Distance K in Binary Tree
#
from typing import *

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        parents = dict()
        vis = set()
        res = []

        def find_parent(node: TreeNode, parent: TreeNode):
            if not node:
                return
            parents[node] = parent
            find_parent(node.left, node)
            find_parent(node.right, node)

        find_parent(root, None)

        def dfs(node: TreeNode, dist: int):
            if not node or node in vis:
                return
            vis.add(node)
            if dist == 0:
                res.append(node.val)
                return
            
            dist -= 1
            dfs(parents[node], dist)
            dfs(node.left, dist)
            dfs(node.right, dist)

        dfs(target, k)
        return res


# @lc code=end

