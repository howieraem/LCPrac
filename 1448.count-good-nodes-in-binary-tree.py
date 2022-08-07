#
# @lc app=leetcode id=1448 lang=python3
#
# [1448] Count Good Nodes in Binary Tree
#

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
    # T: O(n)
    # S: O(h), h := tree height or max depth, recursion stack
    def goodNodes(self, root: TreeNode) -> int:
        return self.helper(root, float('-inf'))

    @staticmethod
    def helper(node: TreeNode, cur_max: float) -> int:
        if not node:
            return 0
        ans = 0
        if node.val >= cur_max:
            ans += 1
            cur_max = node.val
        ans += Solution.helper(node.left, cur_max)
        ans += Solution.helper(node.right, cur_max)
        return ans
        
# @lc code=end

