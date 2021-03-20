#
# @lc app=leetcode.cn id=111 lang=python3
#
# [111] 二叉树的最小深度
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        # BFS
        if not root:
            return 0
        q = deque([root])
        ans = 1
        while q:
            for _ in range(len(q)):
                cur = q.popleft()
                if not cur.left and not cur.right:
                    return ans
                if cur.left:
                    q.append(cur.left)
                if cur.right:
                    q.append(cur.right)
            ans += 1
        return ans

# @lc code=end

