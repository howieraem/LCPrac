#
# @lc app=leetcode.cn id=105 lang=python3
#
# [105] 从前序与中序遍历序列构造二叉树
#
from typing import List

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    """
    Preorder:
        [root, [Preorder of left subtree], [Preorder of right subtree]]

    Inorder:
        [[Inorder of left subtree], root, [Inorder of right subtree]]
    """

    # def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
    #     """Original solution with list slicings (which is slow)."""
    #     if not preorder or not inorder:
    #         return None
    #     root = TreeNode(preorder[0])
    #     i = inorder.index(root.val)  # uniqueness
    #     root.left = self.buildTree(preorder[1:i+1], inorder[:i])
    #     root.right = self.buildTree(preorder[i+1:], inorder[i+1:])
    #     return root

    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder or not inorder:
            return None
        hashmap = {elem:i for i, elem in enumerate(inorder)}
        pre_idx = 0

        def helper(in_start, in_end):
            nonlocal pre_idx
            if in_start > in_end:
                return None
            val = preorder[pre_idx]
            i = hashmap[val]   # avoid using `list.index()`
            root = TreeNode(val)
            pre_idx += 1
            root.left = helper(in_start, i-1)
            root.right = helper(i+1, in_end)
            return root
        
        return helper(0, len(preorder)-1)


# @lc code=end

# p = [3, 9, 20, 15, 7]
# i = [9, 3, 15, 20, 7]
# s = Solution()
# tn = s.buildTree(p, i)
# print(tn.val, tn.left.val, tn.right.val, tn.right.left.val, tn.right.right.val)
