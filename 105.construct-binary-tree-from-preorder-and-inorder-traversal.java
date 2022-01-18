import java.util.*;
/*
 * @lc app=leetcode id=105 lang=java
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */
/**
 * Definition for a binary tree node.
 */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

// @lc code=start
class Solution {
    Map<Integer, Integer> inorder_idx;

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        inorder_idx = new HashMap<>();
        for (int i = 0; i < inorder.length; ++i) {
            inorder_idx.put(inorder[i], i);
        }
        return helper(preorder, 0, preorder.length - 1, 
                      inorder, 0, inorder.length);
    }

    private TreeNode helper(int[] pre, int preL, int preR, 
                            int[] in, int inL, int inR) {
        if (preL > preR)  return null;

        int rootVal = pre[preL];
        int rootIdxIn = inorder_idx.get(rootVal);
        int leftSubTreeSize = rootIdxIn - inL;

        TreeNode root = new TreeNode(rootVal);
        root.left = helper(pre, preL + 1, preL + leftSubTreeSize, 
                           in, inL, rootIdxIn - 1);
        root.right = helper(pre, preL + leftSubTreeSize + 1, preR, 
                            in, rootIdxIn + 1, inR);
        return root;
    }
}
// @lc code=end
