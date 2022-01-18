#
# @lc app=leetcode.cn id=404 lang=python3
#
# [404] 左叶子之和
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        if not root:
            return 0
        ans = 0
        if root.left and not root.left.left and not root.left.right:
            # current left child is a leaf node
            ans = root.left.val
        ans += self.sumOfLeftLeaves(root.left)
        ans += self.sumOfLeftLeaves(root.right)
        return ans
        
# @lc code=end

