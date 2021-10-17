import java.util.*;
/*
 * @lc app=leetcode id=106 lang=java
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private Map<Integer, Integer> inorder_idx;

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        inorder_idx = new HashMap<>();
        for (int i = 0; i < inorder.length; ++i) {
            inorder_idx.put(inorder[i], i);
        }
        return helper(inorder, 0, inorder.length - 1, 
                      postorder, 0, postorder.length - 1);
    }

    private TreeNode helper(int[] in, int inL, int inR, 
                            int[] post, int postL, int postR) {
        if (inL > inR)  return null;

        int rootVal = post[postR]; 
        int rootIdxIn = inorder_idx.get(rootVal);
        int leftSubTreeSize = rootIdxIn - inL;

        TreeNode root = new TreeNode(rootVal);
        root.left = helper(in, inL, rootIdxIn - 1, 
                           post, postL, postL + leftSubTreeSize - 1);
        root.right = helper(in, rootIdxIn + 1, inR, 
                            post, postL + leftSubTreeSize, postR - 1);
        return root;
    }
}
// @lc code=end

