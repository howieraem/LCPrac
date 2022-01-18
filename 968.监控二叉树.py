#
# @lc app=leetcode.cn id=968 lang=python3
#
# [968] 监控二叉树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minCameraCover(self, root: TreeNode) -> int:
        """Traversal:
            Post-order is appropriate because we are finding
            the minimum number of camera so the first few 
            cameras should be placed at parent of leaf nodes.
        
        Cases on node:
            0. not covered
            1. has camera
            2. covered
        """
        ans = 0

        def traverse(node):
            if not node:
                # null nodes are assumed covered
                return 2
            nonlocal ans

            '''Post-order traversal'''
            left = traverse(node.left)
            right = traverse(node.right)
            if left == 2 and right == 2:
                # both children are covered, current node not covered
                return 0
            elif not left or not right:
                # current node has or needs a camera
                ans += 1
                return 1
            else:    # if left == 1 or right == 1:
                # current node covered
                return 2
        
        if traverse(root) == 0:
            # root is not yet covered
            ans += 1
        return ans
        
# @lc code=end

