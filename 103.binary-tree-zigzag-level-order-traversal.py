#
# @lc app=leetcode id=103 lang=python3
#
# [103] Binary Tree Zigzag Level Order Traversal
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
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        if not root:
            return res
        q = deque()
        q.append(root)
        # i = 0

        while len(q):
            qs = len(q)
            lvl = []
            # if i & 1:
            if len(res) & 1:
                # If level index is odd, reverse the direction of 
                # polling as well as pushing
                for _ in range(qs):
                    node: TreeNode = q.pop()
                    lvl.append(node.val)  # visit
                    if node.right:
                        q.appendleft(node.right)
                    if node.left:
                        q.appendleft(node.left)
            else:
                # Same as Q102
                for _ in range(qs):
                    node: TreeNode = q.popleft()
                    lvl.append(node.val)  # visit
                    if node.left:
                        q.append(node.left)
                    if node.right:
                        q.append(node.right)

            # i += 1
            res.append(lvl)
        return res
    
    # Note that for a DFS solution, we have to first do the DFS version of Q102,
    # and then manually reverse the order of odd levels in res 

# @lc code=end

