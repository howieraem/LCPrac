#
# @lc app=leetcode.cn id=337 lang=python3
#
# [337] 打家劫舍 III
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rob(self, root: TreeNode) -> int:
        def robNode(root):
            if not root:
                return 0, 0
            left_res = robNode(root.left)
            right_res = robNode(root.right)
            # If not rob current node, result is maximum sum of children results (regardless of rob or not)
            res_not_rob = max(left_res[0], left_res[1]) + max(right_res[0], right_res[1])
            # If rob current node, result is sum of current node and children `not_rob` results
            res_rob = left_res[0] + right_res[0] + root.val
            return res_not_rob, res_rob

        return max(robNode(root))
        
# @lc code=end

