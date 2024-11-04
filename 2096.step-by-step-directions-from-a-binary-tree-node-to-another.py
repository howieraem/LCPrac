#
# @lc app=leetcode id=2096 lang=python3
#
# [2096] Step-By-Step Directions From a Binary Tree Node to Another
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
    # 1. Build (reversed) paths for both start and destination from the root.
    # 2. Remove common prefix path.
    # 3. Replace all steps in the remaining start path with 'U' and 
    #    then append the path from common ancestor to destination.
    # T: O(n)
    # S: O(n) 
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        path_s, path_d = [], []
        self.find(root, startValue, path_s)
        self.find(root, destValue, path_d)
        # Now path_s order is from start node to root, and similar for path_d.
        # Remove the common "prefix" paths.
        while len(path_s) > 0 and len(path_d) > 0 and path_s[-1] == path_d[-1]:
            path_s.pop()
            path_d.pop()
        return 'U' * len(path_s) + "".join(reversed(path_d))

    @staticmethod
    def find(node: Optional[TreeNode], val: int, path: List[str]) -> bool:
        if node is None:
            return False
        if node.val == val:
            return True
        if Solution.find(node.left, val, path):
            path.append('L')
        elif Solution.find(node.right, val, path):
            path.append('R')
        return len(path) > 0
        

# @lc code=end

