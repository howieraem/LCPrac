/*
 * @lc app=leetcode.cn id=110 lang=java
 *
 * [110] 平衡二叉树
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
    public boolean isBalanced(TreeNode root) {
        return helper(root) != -1;
    }

    public int helper(TreeNode root) {
        if (root == null)  return 0;
        int left = helper(root.left);
        if (left == -1)  return -1;  // prune, reducing unnecessaary computation
        int right = helper(root.right);
        if (right == -1)  return -1;  // prune, reducing unnecessaary computation
        return Math.abs(right - left) < 2 ? Math.max(left, right) + 1 : -1;
    }
}
// @lc code=end

