#
# @lc app=leetcode id=427 lang=python3
#
# [427] Construct Quad Tree
#
from typing import *

class Node:
    def __init__(self, val=False, isLeaf=False, topLeft=None, topRight=None, bottomLeft=None, bottomRight=None):
        self.val: bool = val
        self.isLeaf: bool = isLeaf
        self.topLeft: Node = topLeft
        self.topRight: Node = topRight
        self.bottomLeft: Node = bottomLeft
        self.bottomRight: Node = bottomRight

# @lc code=start
"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    # T: O(n ^ 2)
    # S: O(log(n)) recursion stack
    def construct(self, grid: List[List[int]]) -> 'Node':
        def helper(r, c, n) -> 'Node':
            node = Node(grid[r][c] != 0, True, None, None, None, None)
            if n == 1:
                return node
            n >>= 1
            top_left = helper(r, c, n)
            top_right = helper(r, c + n, n)
            bottom_left = helper(r + n, c, n)
            bottom_right = helper(r + n, c + n, n)

            if not (
                top_left.isLeaf and 
                top_right.isLeaf and 
                bottom_left.isLeaf and 
                bottom_right.isLeaf and 
                top_left.val == top_right.val == bottom_left.val == bottom_right.val
            ):
                node.topLeft = top_left
                node.topRight = top_right
                node.bottomLeft = bottom_left
                node.bottomRight = bottom_right
                node.isLeaf = False
            return node

        return helper(0, 0, len(grid))

# @lc code=end

