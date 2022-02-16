#
# @lc app=leetcode id=124 lang=python3
#
# [124] Binary Tree Maximum Path Sum
#
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
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        ans = -2 ** 31

        # A nested function seems faster than a class member function
        def dfs(node: TreeNode):
            if not node:
                return 0
            left_sum = dfs(node.left)
            right_sum = dfs(node.right)

            nonlocal ans
            ans = max(ans, node.val + left_sum + right_sum)

            # choice: left path, right path, or neither
            return max(0, node.val + max(left_sum, right_sum))  

        dfs(root)
        return ans

    

# @lc code=end

