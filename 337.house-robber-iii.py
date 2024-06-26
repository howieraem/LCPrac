#
# @lc app=leetcode id=337 lang=python3
#
# [337] House Robber III
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
    def rob(self, root: Optional[TreeNode]) -> int:
        return max(self.helper(root))

    @staticmethod
    def helper(node: TreeNode):
        if not node:
            return 0, 0
        l_rob_ret, l_no_rob_ret = Solution.helper(node.left)
        r_rob_ret, r_no_rob_ret = Solution.helper(node.right)
        rob_ret = node.val + l_no_rob_ret + r_no_rob_ret

        # Node that between any 2 robbed houses, the number of houses 
        # not robbed can be greater than 1
        no_rob_ret = max(l_rob_ret, l_no_rob_ret) + max(r_rob_ret, r_no_rob_ret)
        
        return rob_ret, no_rob_ret

# @lc code=end

