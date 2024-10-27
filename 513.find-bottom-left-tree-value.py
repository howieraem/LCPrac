#
# @lc app=leetcode id=513 lang=python3
#
# [513] Find Bottom Left Tree Value
#
from collections import deque
from typing import *

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    # Variant of level order traversal BFS
    # T: O(n)
    # S: O(n)
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        queue = deque()
        queue.append(root)

        ans = None

        while len(queue) > 0:
            node = queue.popleft()

            ans = node.val

            # Traverse right child first, so that the last node in queue 
            # is guaranteed the bottom left
            if node.right is not None:
                queue.append(node.right)
            if node.left is not None:
                queue.append(node.left)

        return ans

# @lc code=end

