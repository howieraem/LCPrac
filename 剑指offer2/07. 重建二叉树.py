# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        self.inorder_idx = {e: i for i, e in enumerate(inorder)}
        return self.helper(preorder, 
                           inorder, 
                           0, 
                           len(preorder) - 1, 
                           0, 
                           len(inorder) - 1)

    def helper(self,
               preorder, 
               inorder, 
               preorder_start, 
               preorder_end, 
               inorder_start, 
               inorder_end):
        if preorder_start > preorder_end:  # or inorder_start > inorder_end:
            return None

        root_val = preorder[preorder_start]

        # inorder_root_idx = inorder_start
        # while inorder[inorder_root_idx] != root_val:
        #     inorder_root_idx += 1
        inorder_root_idx = self.inorder_idx[root_val]

        left_subtree_sz = inorder_root_idx - inorder_start
        root = TreeNode(root_val)
        root.left = self.helper(preorder, 
                                inorder, 
                                preorder_start + 1, 
                                preorder_start + left_subtree_sz,
                                inorder_start,
                                inorder_root_idx - 1)
        root.right = self.helper(preorder, 
                                 inorder, 
                                 preorder_start + left_subtree_sz + 1,
                                 preorder_end,
                                 inorder_root_idx + 1,
                                 inorder_end)
        return root

