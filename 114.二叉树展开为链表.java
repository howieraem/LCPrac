/*
 * @lc app=leetcode.cn id=114 lang=java
 *
 * [114] 二叉树展开为链表
 */

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
    public void flatten(TreeNode root) {
        if (root == null)  return;

        flatten(root.left);
        flatten(root.right);

        // post-order traversal, left and right subtrees already flattened
        TreeNode left = root.left, right = root.right;

        // connect left subtree to the right of current node
        root.left = null;
        root.right = left;

        // find the end of left subtree which is just connected to the right and attach the right subtree
        TreeNode ptr = root;
        while (ptr.right != null)  ptr = ptr.right;
        ptr.right = right;
    }
}
// @lc code=end

