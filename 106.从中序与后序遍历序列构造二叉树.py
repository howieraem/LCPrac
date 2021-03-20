#
# @lc app=leetcode.cn id=106 lang=python3
#
# [106] 从中序与后序遍历序列构造二叉树
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
    Inorder:
        [[Inorder of left subtree], root, [Inorder of right subtree]]

    Postorder:
        [[Postorder of left subtree], [Postorder of right subtree], root]
    """
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        """Original solution with list slicings (which is slow)."""
        if not postorder or not inorder:
            return None
        root = TreeNode(postorder[-1])
        i = inorder.index(root.val)  # uniqueness
        root.left = self.buildTree(inorder[:i], postorder[:i])
        root.right = self.buildTree(inorder[i+1:], postorder[i:-1])
        return root

    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if not postorder or not inorder:
            return None
        hashmap = {elem:i for i, elem in enumerate(inorder)}
        post_idx = -1

        def helper(in_start, in_end):
            nonlocal post_idx
            if in_start > in_end:
                return None
            val = postorder[post_idx]
            i = hashmap[val]   # avoid using `list.index()`
            root = TreeNode(val)
            post_idx -= 1

            # build right subtree before left subtree because `post_idx` is negative
            root.right = helper(i+1, in_end)
            root.left = helper(in_start, i-1)
            return root
        
        return helper(0, len(postorder)-1)
    
# @lc code=end
s = Solution()
tn = s.buildTree([9,3,15,20,7], [9,15,7,20,3])
print(tn.val, tn.left.val, tn.right.val, tn.right.left.val, tn.right.right.val)
