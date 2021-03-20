#
# @lc app=leetcode.cn id=257 lang=python3
#
# [257] 二叉树的所有路径
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    # def binaryTreePaths(self, root: TreeNode) -> List[str]:
    #     res = []
    #     if not root:
    #         return res
    #
    #     def backtrack(path: list, root):
    #         path.append('%d' % root.val)
    #         if not root.left and not root.right:
    #             res.append('->'.join(path))
    #
    #         if root.left:
    #             backtrack(path, root.left)
    #       
    #         if root.right:
    #             backtrack(path, root.right)
    #         path.pop()
    #
    #     backtrack([], root)
    #     return res

    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        res = []

        def helper(path, root):
            if root:
                path += '%d' % root.val
                if not root.left and not root.right:
                    res.append(path)
                else:
                    path += '->'
                    helper(path, root.left)
                    helper(path, root.right)
        
        helper('', root)
        return res


# @lc code=end

