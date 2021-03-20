#
# @lc app=leetcode.cn id=637 lang=python3
#
# [637] 二叉树的层平均值
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        # similar idea to question [102]
        if not root:
            return []
        res = []
        q = deque()
        q.append(root)
        while q:
            lvl_size = len(q)
            lvl_sum = 0.
            for _ in range(lvl_size):
                node = q.popleft()
                lvl_sum += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            res.append(lvl_sum / lvl_size)
        return res
        
# @lc code=end

