#
# @lc app=leetcode id=662 lang=python3
#
# [662] Maximum Width of Binary Tree
#
from collections import deque
from typing import Optional

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
    # T: O(n), n := no. of nodes
    # S: O(n)
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        
        ans = 1
        q = deque()
        q.append((root, 0))  # (node, relative_idx)

        while len(q) > 0:
            l = q[0][1]
            r = q[-1][1]
            ans = max(ans, r - l + 1)

            qs = len(q)
            for _ in range(qs):
                node, idx = q.popleft()
                idx -= l   # level offset
                idx <<= 1  # binary tree, mult 2
                if node.left is not None:
                    q.append((node.left, idx + 1))
                if node.right is not None:
                    q.append((node.right, idx + 2))

        return ans

# @lc code=end

