#
# @lc app=leetcode id=637 lang=python3
#
# [637] Average of Levels in Binary Tree
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
    # BFS level order traversal
    # T: O(n)
    # S: O(n)
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        if root is None:
            return []
        
        q: Deque[TreeNode] = deque()
        q.append(root)

        res = []
        while len(q) > 0:
            qs = len(q)
            lvl_sz = 0
            lvl_sum = 0.0
            for _ in range(qs):
                node = q.popleft()
                lvl_sz += 1
                lvl_sum += node.val
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)
            res.append(lvl_sum / lvl_sz)
        
        return res

# @lc code=end

