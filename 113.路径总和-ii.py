#
# @lc app=leetcode.cn id=113 lang=python3
#
# [113] 路径总和 II
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        res = []
        
        def backtrack(node, path, cur_sum):
            if not node:
                return
            cur_sum += node.val
            path.append(node.val)
            if not node.left and not node.right and cur_sum == sum:
                res.append(path[:])     # append a copy of current `path`
            else:
                backtrack(node.left, path, cur_sum)
                backtrack(node.right, path, cur_sum)
            path.pop()

        backtrack(root, [], 0)
        return res

# @lc code=end

