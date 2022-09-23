#
# @lc app=leetcode id=102 lang=python3
#
# [102] Binary Tree Level Order Traversal
#
from collections import deque
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
    # Solution 1: BFS
    # T: O(n)
    # S: O(n)
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        if not root:
            return res
        q = deque()
        q.append(root)

        while len(q):
            qs = len(q)
            lvl = []
            for _ in range(qs):
                node: TreeNode = q.popleft()
                lvl.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            if len(lvl):
                res.append(lvl)
        return res
    '''

    # Solution 2: DFS
    # T: O(n)
    # S: O(n)
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        Solution.dfs(root, 0, res)
        return res
    
    @staticmethod
    def dfs(node: TreeNode, height: int, res: List[List[int]]):
        if not node:
            return
        if height >= len(res):
            res.append([])
        res[height].append(node.val)
        height += 1
        Solution.dfs(node.left, height, res)
        Solution.dfs(node.right, height, res)

# @lc code=end

